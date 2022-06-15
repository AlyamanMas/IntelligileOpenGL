#include "../gdi/Drawable.hpp"
#include <cstdint>

struct Color {
  uint8_t red, green, blue;
};

class Shape : Drawable {
public:
  virtual float getWidth() = 0;
  virtual float getHeight() = 0;
  ~Shape(){};

  // Getters and setters
  Color get_color() const { return color; };
  void set_color(Color color) { this->color = color; };

  float get_angle() const { return angle; };
  void set_angle(float angle) { this->angle = angle; };

private:
  Color color;
  float angle;
};
