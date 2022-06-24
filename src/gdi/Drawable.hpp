#include "Point.hpp"
#include <vector>

namespace gdi {
class Drawable {
public:
  virtual ~Drawable(){};
  virtual std::vector<GPoint> provide_points() = 0;
};

} // namespace gdi
