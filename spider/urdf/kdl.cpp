#include <urdf/model.h>
#include <kdl/tree.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <kdl/chain.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolverpos_nr_jl.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/jntarray.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

namespace py = pybind11;

// Cargar URDF y convertir a KDL::Tree
KDL::Tree loadRobotTree(const std::string& urdf_file) {
    std::ifstream file(urdf_file);
    if(!file.is_open()) throw std::runtime_error("No se pudo abrir URDF");
    std::string xml((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    urdf::Model model;
    if (!model.initString(xml)) throw std::runtime_error("URDF inválido");

    KDL::Tree tree;
    if (!kdl_parser::treeFromUrdfModel(model, tree)) throw std::runtime_error("Error al convertir URDF a KDL Tree");

    return tree;
}

// Función genérica para calcular IK de una pierna
std::vector<double> ik_leg(const std::string& urdf_path,
                           const std::string& tip_name,
                           const std::vector<double>& target_pos)
{
    auto tree = loadRobotTree("Robot.urdf");

    KDL::Chain chain;
    if(!tree.getChain("base_link", "l_Spider_foot_backleft001", chain))
        throw std::runtime_error("Chain no encontrada: " + tip_name);

    unsigned int nj = chain.getNrOfJoints();
    KDL::JntArray q_min(nj), q_max(nj), q_init(nj), q_out(nj);

    // Limites de articulaciones
    for(unsigned int i=0;i<nj;i++){
        q_min(i) = -1.57;
        q_max(i) = 1.57;
        q_init(i) = 0.0;  // valores iniciales
    }

    KDL::ChainFkSolverPos_recursive fk_solver(chain);
    KDL::ChainIkSolverVel_pinv ik_vel_solver(chain);
    KDL::ChainIkSolverPos_NR_JL ik_solver(chain, q_min, q_max, fk_solver, ik_vel_solver, 100, 1e-6);

    KDL::Frame target_frame(KDL::Vector(target_pos[0], target_pos[1], target_pos[2]));

    if(ik_solver.CartToJnt(q_init, target_frame, q_out) < 0)
        throw std::runtime_error("No se pudo calcular IK para " + tip_name);

    std::vector<double> result(nj);
    for(unsigned int i=0;i<nj;i++) result[i] = q_out(i);

    return result;
}

// Exponer a Python
PYBIND11_MODULE(kdl_spider, m) {
    m.def("ik_leg", &ik_leg, 
         py::arg("target_pos"),
        "Calcular IK de una pierna del robot (base_link -> tip_name)");
}

