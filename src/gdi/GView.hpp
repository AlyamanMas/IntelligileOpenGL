#ifndef GVIEW_H_
#define GVIEW_H_

#include <sys/types.h>
#include <vector>

// #ifdef OPENGL_BACKEND
// GLAD for OpenGL Extensions
#include <glad/glad.h>
// For drawing the window as a GLContext crossplatform
#include <GLFW/glfw3.h>
// #endif // OPENGL_BACKEND

#include "Drawable.hpp"

namespace gdi {
class GView {
public:
  GView(uint height, uint width);
  virtual ~GView() {
    glfwDestroyWindow(window);
    glfwTerminate();
  };

  void display_window();

  // TODO: width and height shouldn't be field
  // attributes, but rather get should return from window object
  // and set must invoke window object to resize, otherwise
  // field attributes and real window stay out of sync
  
  // Getters and setters
  // float get_width() const;
  // float get_height() const;

  virtual void set_width(uint width);
  virtual void set_height(uint height);

private:
  // #ifdef OPENGL_BACKEND
  GLFWwindow *window;
  // #endif // OPENGL_BACKEND
  uint height, width;
  std::vector<Drawable> shapes{};
};

} // namespace gdi
#endif // GVIEW_H_
