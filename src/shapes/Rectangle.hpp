#include "Shape.hpp"
#include <vector>

class Rectangle : public Shape {
public:
  Rectangle(float w, float h);
  ~Rectangle(){};

  // Drawable implementation
  std::vector<float> provide_points();

  // Getters and setters
  float get_width();
  float get_height();

protected:
  float width;
  float height;
};
