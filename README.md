# ilumin-8

## Before Anti-aliasing
![Image](https://github.com/user-attachments/assets/2841ddd9-dede-439e-808a-dc8b56161f46)

## After Anti-aliasing
![Image](https://github.com/user-attachments/assets/2b4258af-af84-4b20-bd53-52b9581675dc)
- The above looks choppy because anti-aliasing is a GPU heavy operation (although ray tracing in general is a GPU heavy operation). The lack of a GPU hit here.

## Overview
**ilumin-8** is a real-time ray tracing project implemented in C++. It utilizes **GLFW** for window management and **OpenGL** for rendering, allowing for real-time visualization of a 3D scene. The project features a movable light source and sphere object, supporting interactive controls for dynamic scene exploration.

## Features
- **Real-time rendering using OpenGL**
- **Ray tracing in 3D space** for realistic lighting and shading
- **GLFW for window creation and event handling**
- **Movable camera and objects** to simulate real-world interactions
- **Anti-aliasing implementation** for smooth image rendering

## Technologies Used
- **C++** for core implementation
- **GLFW** for window management and user input
- **OpenGL** for pixel rendering
- **Custom-built ray tracing engine**
- **Mathematical utilities** for vector and matrix calculations

## Installation & Setup
### Prerequisites
Ensure you have the following installed:
- **C++17 or later**
- **GLFW** (`sudo dnf install glfw` on Fedora, `sudo apt install libglfw3-dev` on Ubuntu)
- **OpenGL** drivers
- **CMake** (optional but recommended for build automation)

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/hirdyanshKanethia/ilumin-8.git
   cd ilumin-8
   ```
2. Compile the project:
   ```bash
   g++ -o ilumin-8 src/*.cpp -Iinclude -lglfw -lGL -std=c++17
   ```
3. Run the executable:
   ```bash
   ./ilumin-8
   ```

## Usage
### Controls
- **Mouse movement**: Adjusts light position dynamically.
- **W / S**: Move sphere up/down.
- **A / D**: Move sphere left/right.
- **Z (Shift+Z)**: Move sphere forward/backward.
- **ESC**: Exit the program.

### Rendering Pipeline
1. **Scene Setup**: A 3D scene with objects (e.g., a sphere) is created.
2. **Ray Generation**: The camera casts rays through each pixel.
3. **Intersection Testing**: The rays check for intersections with objects in the scene.
4. **Lighting Computation**: The system calculates shading based on light position.
5. **Framebuffer Rendering**: The computed colors are stored and displayed via OpenGL.

## License
This project is licensed under the MIT License.

## Acknowledgments
- **Peter Shirley's "Ray Tracing in One Weekend"** for foundational concepts.
- **OpenGL & GLFW** for rendering support.
