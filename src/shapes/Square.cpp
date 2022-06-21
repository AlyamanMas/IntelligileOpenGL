#include "Square.hpp"

using namespace shapes;
using namespace gdi;

Square::Square(float s) : Rectangle(s, s){};

// std::vector<float> Square::provide_points(){};
void Square::set_width(float w) {
  this->width = w;
  this->height = w;
};
void Square::set_height(float h) {
  this->width = h;
  this->height = h;
};
