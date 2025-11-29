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

    #print("KI: ", alpha, beta, gamma)
    return  alpha, beta, gamma 
"""

def get_tranf_matrix():

    # Variables simbólicas
    q0, q1, q2 = sp.symbols('q0 q1 q2')
    hip, leg, foot = sp.symbols('hip leg foot')

    # --- A0 ---
    R0 = sp.Matrix([
        [sp.cos(q0), -sp.sin(q0), 0, 0],
        [sp.sin(q0),  sp.cos(q0), 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ])

    T0 = sp.Matrix([
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, hip],
        [0, 0, 0, 1]
    ])

    RA0 = sp.Matrix([
        [1, 0,             0,              0],
        [0, sp.cos(-sp.pi/2), -sp.sin(-sp.pi/2), 0],
        [0, sp.sin(-sp.pi/2),  sp.cos(-sp.pi/2), 0],
        [0, 0,             0,              1]
    ])

    A0 = R0 * T0 * RA0


    # --- A1 ---
    R1 = sp.Matrix([
        [sp.cos(q1), -sp.sin(q1), 0, 0],
        [sp.sin(q1),  sp.cos(q1), 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ])

    T1 = sp.Matrix([
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, leg],
        [0, 0, 0, 1]
    ])

    A1 = R1 * T1


    # --- A2 ---
    R2 = sp.Matrix([
        [sp.cos(q2 + sp.pi/2), -sp.sin(q2 + sp.pi/2), 0, 0],
        [sp.sin(q2 + sp.pi/2),  sp.cos(q2 + sp.pi/2), 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ])

    T2 = sp.Matrix([
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, foot],
        [0, 0, 0, 1]
    ])

    RA2 = sp.Matrix([
        [1, 0,           0,           0],
        [0, sp.cos(sp.pi/2), -sp.sin(sp.pi/2), 0],
        [0, sp.sin(sp.pi/2),  sp.cos(sp.pi/2), 0],
        [0, 0,           0,           1]
    ])

    A2 = R2 * T2 * RA2


    # Transformación final simbólica
    T = A0 * A1 * A2

    ultima_columna = sp.pretty(T[:, 3])
    print(sp.pretty(A0))
    print(sp.pretty(A1))
    print(sp.pretty(A2))
    print(ultima_columna)


q0, q1, q2 = sp.symbols('q0 q1 q2')
hip, leg, foot = sp.symbols('hip leg foot')

def dh_matrix(a, alpha, d, theta):
    return sp.Matrix([
        [sp.cos(theta), -sp.cos(alpha)*sp.sin(theta),  sp.sin(theta)*sp.sin(alpha), a*sp.cos(theta)],
        [sp.sin(theta),  sp.cos(theta)*sp.cos(alpha), -sp.sin(alpha)*sp.cos(theta), a*sp.sin(theta)],
        [0,              sp.sin(alpha),               sp.cos(alpha),               d],
        [0,              0,                           0,                           1]
    ])

A0 = dh_matrix(hip, -sp.pi/2, 0, q0)
A1 = dh_matrix(leg, 0, 0, q1)
A2 = dh_matrix(foot, sp.pi/2, 0, q2+sp.pi/2)

T = sp.simplify(A0 * A1 * A2)

px, py, pz = T[0,3], T[1,3], T[2,3]
sp.pprint(T[:, 3])


# Parámetros del robot/pierna
hip = 0.37
leg = 0.507
foot = 0.9


def inverse_kinematics(x, y, z):
    # q0 es directo
    q0 = math.atan2(y, x)
    
    # Distancia horizontal desde el eje de rotación
    r = math.sqrt(x**2 + y**2)
    
    # Resolvemos q1 usando arctan
    # Ecuaciones derivadas:
    # sin(q1+q2) = (hip + leg*cos(q1) - r)/foot
    # cos(q1+q2) = -(z + leg*sin(q1))/foot
    # Convertimos en forma A*cos(q1) + B*sin(q1) = C
    A = leg
    B = foot * ((r - hip)/foot)
    C = -z
    
    # Ecuación: A*sin(q1) + B*cos(q1) = C
    # q1 = arctan2(A, B)
    # Ajustamos usando fórmula general: sin(q1+alpha) = C/sqrt(A^2+B^2)
    alpha = math.atan2(B, A)
    R = math.sqrt(A**2 + B**2)
    
    if abs(C/R) > 1:
        raise ValueError("Posición no alcanzable")
    
    q1 = math.asin(C / R) - alpha
    
    # Ahora q2
    sin_q1q2 = (hip + leg*math.cos(q1) - r)/foot
    cos_q1q2 = -(z + leg*math.sin(q1))/foot
    q1q2 = math.atan2(sin_q1q2, cos_q1q2)
    q2 = q1q2 - q1
    
    return q0, q1, q2

# Ejemplo:
x, y, z = 0.5, 0.2, -0.3
q0, q1, q2 = inverse_kinematics(x, y, z)
print("q0 =", q0)
print("q1 =", q1)
print("q2 =", q2)
"""