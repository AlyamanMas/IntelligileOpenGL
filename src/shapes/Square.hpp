#include "Rectangle.hpp"
#include <vector>

namespace shapes {
class Square : public Rectangle {
public:
  Square(float s);
  virtual ~Square(){};

  // Override width and height setters
  void set_width(float w) override;
  void set_height(float h) override;

  // Drawable implementation
  // std::vector<gdi::GPoint> provide_points() override;

  // // Getters and setters
  // float get_width();
  // float get_height();
};
} // namespace shapes
