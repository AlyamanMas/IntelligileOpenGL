#include "./Context.hpp"
#include <GLFW/glfw3.h>

class Drawable {
public:
  virtual void drawToContext(Context context, float x, float y) = 0;
};
