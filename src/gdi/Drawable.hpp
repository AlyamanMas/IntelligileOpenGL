#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "Point.hpp"
#include <vector>

namespace gdi {
class Drawable {
public:
  virtual ~Drawable(){};
  virtual std::vector<GPoint> provide_points() = 0;
};

} // namespace gdi

#endif // DRAWABLE_H_
