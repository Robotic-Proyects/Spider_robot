import math
    
def inverse_kinematics(x, y, z, F_OFF, S_OFF, T_OFF):
    hip = 0.37
    leg = 0.507
    foot = 0.8
    # q0: rotación horizontal
    q0 = math.atan2(y, x) - F_OFF
    
    # Distancia horizontal desde la base (plano XZ)
    r = math.sqrt(x**2 + y**2)
    
    # Ley del coseno para q2
    D = ((r**2 + z**2) - leg**2 - foot**2) / (2 * leg * foot)
    if abs(D) > 1:
        return None
    
    q2 = math.atan2(-math.sqrt(1 - D**2), D) - T_OFF # ángulo de la rodilla
    
    # q1: ángulo de la pata
    q1 = math.atan2(z, r) - math.atan2(foot * math.sin(q2), leg + foot * math.cos(q2)) - S_OFF

    if q0 < 0.01 and q0 > -0.01:
        q0 = 0.0
    if q1 < 0.01 and q1 > -0.01:
        q1 = 0.0
    if q2 < 0.01 and q2 > -0.01:
        q2 = 0.0
    
    if q0>=-1 and q0<=1 and q1>=-1.57 and q1<=1.57 and q2>=-1.57 and q2<=1.57:
        return q0, q1, q2

    return q0, q1, q2

def forward_kinematics(q0, q1, q2, F_OFF, S_OFF, T_OFF):
    q0 += F_OFF
    q1 += S_OFF
    q2 += T_OFF

    hip = 0.37
    leg = 0.507
    foot = 0.8

    xp = hip + leg * math.cos(q1) + foot * math.cos(q1 + q2)
    z  = leg * math.sin(q1) + foot * math.sin(q1 + q2)

    x = xp * math.cos(q0)
    y = xp * math.sin(q0)

    return x, y, z