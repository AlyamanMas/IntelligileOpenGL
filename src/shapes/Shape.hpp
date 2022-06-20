#include <cstdint>

#include "../gdi/Drawable.hpp"

struct Color {
  uint8_t red, green, blue;
};

class Shape : public Drawable {
public:
  Shape(Color color, float angle);
  ~Shape(){};

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
