#include <iostream>

// GLAD for OpenGL Extensions
#include <glad/glad.h>
// For drawing the window as a GLContext crossplatform
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "util.hpp"
// #include "./shapes/Square.hpp"

using namespace std;
using namespace gdi;

int main() {
  cout << "Testing shapes: " << endl;
  test_shapes();

  cout << "\nTesting color: " << endl;
  test_gdi_color();
}

int glfw_main() {

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(600, 400, "My Window", 0, 0);
  if (window == NULL) {
    cout << "Failed to create GLFW Window" << endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  gladLoadGL();

  glViewport(0, 0, 600, 400);

  glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);

  do {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (!glfwWindowShouldClose(window));

  glfwDestroyWindow(window);
  glfwTerminate();

  cout << "Hello World!" << endl;
  return 0;
}
