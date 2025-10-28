import pybullet as p
import pybullet_data
import time

# --- Inicialización ---
p.connect(p.GUI)
p.setAdditionalSearchPath(pybullet_data.getDataPath())
p.setGravity(0, 0, -9.8)

# --- Carga del entorno ---
plane = p.loadURDF("plane.urdf")
robot = p.loadURDF("Robot.urdf", basePosition=[0, 0, 0.3])
#cubo = p.loadURDF("cubo.urdf", basePosition=[0, 0, 1])
#caja = p.loadURDF("caja.urdf", basePosition=[0, 0, 1])

p.resetDebugVisualizerCamera(
    cameraDistance=0.3,         # alejada 2 metros
    cameraYaw=0,              # no gira horizontalmente
    cameraPitch=-89.9,        # casi vertical (mirando hacia abajo)
    cameraTargetPosition=[0,0,0]  # apunta al centro de la escena
)

num_joints = p.getNumJoints(robot)
print("Número de joints:", num_joints)
for i in range(num_joints):
    info = p.getJointInfo(robot, i)
    print(i, "→", info[1].decode("utf-8"), "tipo:", info[2])

joint_id = 0
target_velocity = 2.0
max_force = 10.0

while True:
    #.setJointMotorControl2(robot, joint_id, p.VELOCITY_CONTROL, targetVelocity=target_velocity, force=max_force)
    p.stepSimulation()
    
    # Obtener la posición del link hijo del joint
    joint_pos = p.getLinkState(robot, joint_id)[0]
    
    
    time.sleep(1./240.)
