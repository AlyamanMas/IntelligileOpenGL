#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.hpp"
#include <vector>

namespace shapes {
class Rectangle : public Shape {
public:
  Rectangle(float w, float h);
  virtual ~Rectangle(){};

  // Drawable implementation
  std::vector<gdi::GPoint> provide_points();

  // Getters and setters
  float get_width();
  float get_height();

  virtual void set_width(float w);
  virtual void set_height(float h);

protected:
  float width;
  float height;
};
} // namespace shapes

#endif // RECTANGLE_H_
