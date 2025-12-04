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

    initial_pose = [0, 1.66, 1.55]
    if pose_interface == 1:
        initial_pose = [0, initial_pose[1] + (-1.57), initial_pose[2] + (-1.57)]
    return initial_pose

def get_configurations(pose_interface, ejeX, ejeY, ejeZ):
    
    #Size
    HIP_LEG = 37.75
    LEG_FOOT = 50.92
    FOOT_ENDEFFECTOR = 90.96
    
    desfaceZ = 86
    initial_pose = [0, 1.66, 1.55] #[0, 93.05, 99.7]

    if pose_interface == 0:
        initial_pose = [0, 1.66, 1.55]
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

    print(gamma_rad,alfa_rad,beta_rad)
    return(gamma_rad,alfa_rad,beta_rad)
    
def inverse_kinematics(x, y, z):
    hip = 0.37
    leg = 0.507
    foot = 0.9
    # q0: rotación horizontal
    q0 = math.atan2(y, x)
    
    # Distancia horizontal desde la base (plano XZ)
    r = math.sqrt(x**2 + y**2)
    
    # Ley del coseno para q2
    D = (((r - hip)**2 + z**2) - leg**2 - foot**2) / (2 * leg * foot)
    if abs(D) > 1:
        return None
    
    q2 = math.atan2(-math.sqrt(1 - D**2), D)  # ángulo de la rodilla
    
    # q1: ángulo de la cadera
    q1 = math.atan2(z, r - hip) - math.atan2(foot * math.sin(q2), leg + foot * math.cos(q2))


    if q0 < 0.01 and q0 > -0.01:
        q0 = 0.0
    if q1 < 0.01 and q1 > -0.01:
        q1 = 0.0
    if q2 < 0.01 and q2 > -0.01:
        q2 = 0.0
    
    if q0>=-1 and q0<=1 and q1>=-1.57 and q1<=1.57 and q2>=-1.57 and q2<=1.57:
        return q0, q1, q2
    
    return None

def forward_kinematics(q0, q1, q2):
    if not (-1 <= q0 <= 1 and -1.57 <= q1 <= 1.57 and -1.57 <= q2 <= 1.57):
        return None

    hip = 0.37
    leg = 0.507
    foot = 0.9

    # Coordenadas en el plano X'Z antes de la rotación q0
    xp = hip + leg * math.cos(q1) + foot * math.cos(q1 + q2)
    z  =       leg * math.sin(q1) + foot * math.sin(q1 + q2)

    # Aplicar rotación en torno al eje Z
    x = xp * math.cos(q0)
    y = xp * math.sin(q0)

    return x, y, z

