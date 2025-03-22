#include "color.h"
#include "hittable_list.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"

#include <GLFW/glfw3.h>

const int WIDTH = 800;
const int HEIGHT = 600;

// Global sphere pointer
sphere *sphere1;

hittable_list world;
vec3 light_pos(0, 3, 2); // Moving Light Source

void mouseCallback(GLFWwindow *window, double xpos, double ypos) {
  float norm_x = (xpos / WIDTH) * 2.0 - 1.0;
  float norm_y = (ypos / HEIGHT) * 2.0 - 1.0;
  float prev_z = light_pos[2];

  light_pos = vec3(norm_x * 10.0, norm_y * 10.0, prev_z);
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mods) {
  if (action == GLFW_PRESS || action == GLFW_REPEAT) {
    switch (key) {
    case GLFW_KEY_W:
      if (sphere1->center[1] > -6)
        sphere1->center += point3(0, -0.5, 0); // Move sphere up
      break;
    case GLFW_KEY_S:
      if (sphere1->center[1] < 6)
        sphere1->center += point3(0, 0.5, 0); // Move sphere down
      break;
    case GLFW_KEY_A:
      if (sphere1->center[0] > -8)
        sphere1->center += point3(-0.5, 0, 0); // Move sphere left
      break;
    case GLFW_KEY_D:
      if (sphere1->center[0] < 8)
        sphere1->center += point3(0.5, 0, 0); // Move sphere right
      break;
    case GLFW_KEY_Z:
      if (mods & GLFW_MOD_SHIFT) { // Shift + Z -> Move backward
        if (sphere1->center[2] < -5)
          sphere1->center += point3(0, 0, 0.5);
      } else { // Z -> Move forward
        if (sphere1->center[2] > -20)
          sphere1->center += point3(0, 0, -0.5);
      }
      break;
    case GLFW_KEY_ESCAPE:
      glfwSetWindowShouldClose(window, true);
      break;
    }
  }
}

void renderScene(std::vector<color> &framebuffer) {
  vec3 cam_pos(0, 0, 5);
  float aspect_ratio = float(WIDTH) / HEIGHT;
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      float u = (2.0 * x / WIDTH - 1) * aspect_ratio;
      float v = (1 - 2.0 * y / HEIGHT);
      vec3 ray_dir = unit_vector(vec3(u, v, -1));
      framebuffer[y * WIDTH + x] = ray_color(ray(cam_pos, ray_dir));
    }
  }
}

void drawFramebuffer(const std::vector<color> &framebuffer) {
  std::vector<float> pixel_data(WIDTH * HEIGHT * 3);
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    pixel_data[i * 3] = framebuffer[i].x();
    pixel_data[i * 3 + 1] = framebuffer[i].y();
    pixel_data[i * 3 + 2] = framebuffer[i].z();
  }
  glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_FLOAT, pixel_data.data());
}

int main() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "ilumin-8", NULL, NULL);
  if (!window) {
    std::cerr << "Failed to create window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyCallback);
  glfwSetCursorPosCallback(window, mouseCallback);

  sphere1 = new sphere(point3(0, 0, -10), 5);

  world.add(sphere1);

  std::vector<color> framebuffer(WIDTH * HEIGHT);

  while (!glfwWindowShouldClose(window)) {
    renderScene(framebuffer);
    glClear(GL_COLOR_BUFFER_BIT);
    drawFramebuffer(framebuffer);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
