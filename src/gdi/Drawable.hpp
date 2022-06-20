#include <GLFW/glfw3.h>
#include <vector>

class Drawable {
public:
  virtual std::vector<float> provide_points() = 0;
};
