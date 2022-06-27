#ifndef SHAPE_H_
#define SHAPE_H_

#include <cstdint>

#include "../gdi/Drawable.hpp"

namespace shapes {
struct Color {
  uint8_t red, green, blue;
};

class Shape : public gdi::Drawable {
public:
  Shape(Color color, float angle);
  virtual ~Shape(){};

  virtual float get_width() = 0;
  virtual float get_height() = 0;

  // Getters and setters
  Color get_color() const;
  void set_color(Color color);

  float get_angle() const;
  void set_angle(float angle);

protected:
  Color color;
  float angle;
};
} // namespace shapes

#endif // SHAPE_H_
