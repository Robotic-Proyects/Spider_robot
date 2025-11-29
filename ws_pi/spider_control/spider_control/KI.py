import math
import numpy as np
import sympy as sp

RAD_TO_DEG = 180 / math.pi
"""
def HipoXY(X, Y):
    hipo = math.sqrt(pow(X,2) + pow(Y,2))
    return hipo


def LineaA(d_Z, h_XY, cox):
    linea_a = math.sqrt(  pow(d_Z,2) + pow(h_XY - cox,2) )
    return linea_a


def Gamma(Y, X):
    gam = math.atan(Y/X) * RAD_TO_DEG
    return gam


def Alfa(d_Z, l_A, tibia, femur):
    alf1 = math.acos(d_Z/l_A) * RAD_TO_DEG
    alf2 = math.acos(  (pow(tibia,2)-pow(femur,2)-pow(l_A,2)) / (-2*femur*l_A)) * RAD_TO_DEG
    alf = alf1 + alf2
    return alf

def Beta(l_A, tibia, femur):
    beta = math.acos(  (pow(l_A,2)-pow(tibia,2)-pow(femur,2)) / (-2*tibia*femur)) * RAD_TO_DEG
    return beta
"""
def get_initial_pose(pose_interface):

    initial_pose = [0, 93.05, 99.7]
    if pose_interface == 1:
        initial_pose = [0, initial_pose[1] + (-1.57), initial_pose[2] + (-1.57)]
    return initial_pose

def get_configurations(pose_interface, ejeX, ejeY, ejeZ):
    
    #Size
    HIP_LEG = 37.75
    LEG_FOOT = 50.92
    FOOT_ENDEFFECTOR = 90.96
    
    desfaceZ = 86
    initial_pose = [0, 93.05, 99.7] #[0, 93.05, 99.7]

    if pose_interface == 0:
        initial_pose = [0, 93.05, 99.7]
    elif pose_interface == 1: # Initial pose for walking
        initial_pose = [0, initial_pose[1] + math.degrees(-1.57), initial_pose[2] + math.degrees(-1.57)]
    else:
        print("Introduce 0 or 1")
        return(-1)
    
    hipoXY = HipoXY(ejeX,ejeY)
    lineaAlfa = LineaA(desfaceZ, hipoXY, HIP_LEG)

    gamma = Gamma(ejeY, ejeX)
    alfa = Alfa(desfaceZ, lineaAlfa, FOOT_ENDEFFECTOR, LEG_FOOT)
    beta = Beta(lineaAlfa, FOOT_ENDEFFECTOR, LEG_FOOT)

    gamma_rad = math.radians(gamma - initial_pose[0])
    alfa_rad = math.radians(alfa - initial_pose[1])
    beta_rad = math.radians(beta - initial_pose[2])

    #print("get_conf: ", gamma_rad,alfa_rad,beta_rad)
    return(gamma_rad,alfa_rad,beta_rad)

def KI(x, y, z):

    a, b, c = 37.75, 50.92, 77

    # Evita divisiones por cero
    if x == 0:
        x = 0.01
    if y == 0:
        y = 0.01

    # Pendiente (m)
    m = abs(float(y) / float(x))

    # Cálculos de compensación
    c_1 = c / math.sqrt(m * m + 1)
    c_2 = m * c_1

    if x < 0:
        c_1 = -c_1
    if y < 0:
        c_2 = -c_2

    # Coordenadas suplementarias
    x_supp = x - c_1
    y_supp = y - c_2

    # Longitud del punto C a B
    d = math.sqrt(x_supp**2 + y_supp**2 + z**2)

    # Comprobación de viabilidad física
    if (d > (a + b)) or (d < abs(a - b)):
        print("Not allowed physically speaking")

    # Cálculo de ángulos (en radianes)
    alpha = math.atan2(y, x)
    delta = math.atan2(z, math.sqrt(x_supp**2 + y_supp**2))
    epsilon = math.acos((a**2 + d**2 - b**2) / (2 * a * d))
    beta = epsilon + delta
    gamma = abs(math.acos((a**2 + b**2 - d**2) / (2 * a * b)))

    print("KI: ", alpha, beta, gamma)
    return  alpha, beta, gamma 