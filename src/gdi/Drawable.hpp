#include "Point.hpp"
#include <GLFW/glfw3.h>
#include <vector>

namespace gdi {
class Drawable {
public:
  virtual std::vector<GPoint> provide_points() = 0;
};

} // namespace gdi
