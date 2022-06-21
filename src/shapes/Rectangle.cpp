#include "Rectangle.hpp"
#include <vector>

using namespace shapes;
using namespace gdi;

float Rectangle::get_width() { return this->width; }

float Rectangle::get_height() { return this->height; }

Rectangle::Rectangle(float w, float h)
    : width{w}, height{h}, Shape(Color{0xff, 0xff, 0xff}, 0.0){};

std::vector<GPoint> Rectangle::provide_points() {
  return std::vector<GPoint>{
      // assuming (0,0) is top left
      GPoint{0, 0},                                  // top left
      GPoint{this->get_width(), 0},                  // top right
      GPoint{this->get_width(), this->get_height()}, // bottom right
      GPoint{0, this->get_height()}                  // bottom left
  };
};

void Rectangle::set_width(float w) { this->width = w; };

void Rectangle::set_height(float h) { this->height = h; };
