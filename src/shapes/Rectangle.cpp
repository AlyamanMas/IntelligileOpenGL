#include "Rectangle.hpp"
#include <vector>

float Rectangle::get_width() { return this->width; }

float Rectangle::get_height() { return this->height; }

Rectangle::Rectangle(float w, float h)
    : width{w}, height{h}, Shape(Color{0xff, 0xff, 0xff}, 0.0){};

std::vector<float> Rectangle::provide_points() {
  return std::vector<float>{0, this->get_width(), this->get_height(), 0};
};
