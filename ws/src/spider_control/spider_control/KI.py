import math

RAD_TO_DEG = 180 / math.pi

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

def get_initial_pose(pose_interface):
    initial_pose = [0, 93.05, 99.7]
    initial_pose = [0, initial_pose[1] + math.degrees(-0.7), initial_pose[2] + math.degrees(-0.8)]
    return initial_pose

def get_configurations(pose_interface, ejeX, ejeY, ejeZ):
    
    #Size
    HIP_LEG = 37.75
    LEG_FOOT = 50.92
    FOOT_ENDEFFECTOR = 90.96
    
    desfaceZ = 86
    initial_pose = [0, 93.05, 99.7]

    if pose_interface == 0:
        initial_pose = [0, 93.05, 99.7]
    elif pose_interface == 1: # Initial pose for walking
        initial_pose = [0, initial_pose[1] + math.degrees(-0.7), initial_pose[2] + math.degrees(-0.8)]
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

    print(gamma_rad,alfa_rad,beta_rad)
    return(gamma_rad,alfa_rad,beta_rad)

