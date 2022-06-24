#include <iostream>

// GLAD for OpenGL Extensions
#include <glad/glad.h>
// For drawing the window as a GLContext crossplatform
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "./gdi/GView.hpp"
// #include "./shapes/Square.hpp"

using namespace std;
using namespace gdi;

int main() {
  GView my_view(400,600);
  my_view.display_window();

  return 0;
}


// using namespace shapes;

// void print_points(Shape &s) {
//   cout << "printing points \n";
//   int idx{0};
//   for (auto i : s.provide_points()) {
//     cout << "point " << idx << ": " << i.to_string() << endl;
//     idx++;
//   }
// }

// int main_old() {

  // Rectangle r1(5, 10);

  // print_points(r1);

  // r1.set_height(7);

  // print_points(r1);

  // Square s1(2);
  // print_points(s1);

  // s1.set_height(5);
  // print_points(s1);

  // return 0;
// }

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
