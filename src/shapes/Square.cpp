#include "Square.hpp"

using namespace shapes;

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

std::vector<float> shapes::Square::provide_points() {
  return std::vector<float>{0, this->get_width(), this->get_height(), 0};
};
