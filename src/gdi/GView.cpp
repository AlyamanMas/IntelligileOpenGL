#include "GView.hpp"
#include <vector>

using namespace gdi;

void GView::set_width(uint width){};
void GView::set_height(uint height){};

// float GView::get_width() const {};
// float GView::get_height() const {};
gdi::GView::GView(uint height, uint width)
    : height(height), width(width) {

  // shapes = vector<Drawable>{};

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(width, height, "My Window", 0, 0);
  if (window == NULL) {
    cout << "Failed to create GLFW Window" << endl;
    glfwTerminate();
    // return -1;
  }
  // glfwMakeContextCurrent(window);
};
void gdi::GView::display_window() {
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
};
