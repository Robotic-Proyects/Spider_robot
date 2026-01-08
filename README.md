# 🕷️ Spider Robot - Daisy

Proyecto de simulación y control de un robot tipo *spider* utilizando **ROS 2 Jazzy** y **Gazebo Sim**.

---

## 📦 Requisitos

* Ubuntu compatible con ROS 2 Jazzy
* ROS 2 Jazzy instalado y configurado
* Gazebo Sim
* `colcon`
* Git

---

## 🚀 Instalación
1. Moverte al `src` de tu paquete.

2. Clonar el repositorio (rama `jazzy`):

```bash
git clone -b jazzy https://github.com/usuario/repo.git
```

3. Cargar el entorno de ROS 2 Jazzy:

```bash
source /opt/ros/jazzy/setup.bash
```

4. Compilar el workspace:

```bash
cd ../
colcon build --symlink-install
```

5. Cargar el workspace compilado:

```bash
source install/setup.bash
```

---

## 🧪 Ejecución del simulador

### Mundo con paredes (habitación)

Lanza Gazebo Sim con un mundo personalizado que incluye paredes:

```bash
ros2 launch spider gazebo.launch.py gui:=False use_custom_world:=true world_name:=room
```

### Mundo vacío

Lanza Gazebo Sim con un mundo vacío:

```bash
ros2 launch spider gazebo.launch.py gui:=False
```

### Con interfaz gráfica

Lanza Gazebo Sim con interfaz visual:

```bash
ros2 launch spider gazebo.launch.py gui:=True
```

---

## 🎮 Control del robot

> **Nota:** Cada comando debe ejecutarse en una terminal distinta y con el workspace correctamente *sourced*.

### 1. Nodo lector de teclado

Permite controlar el robot mediante el teclado:

```bash
source install/setup.bash
ros2 run keyboard_reader key_reader
```

### 2. Nodo controlador de movimiento

Publica los comandos de movimiento al robot:

```bash
source install/setup.bash
ros2 run spider_control movement_publisher
```

---

## 📌 Notas adicionales

* Asegúrate de ejecutar `source install/setup.bash` en **cada terminal nueva**.
* El simulador debe estar en ejecución antes de lanzar los nodos de control.







