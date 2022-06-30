#include "./Shape.hpp"

using namespace shapes;

Color Shape::get_color() const { return color; };

void Shape::set_color(Color color) { this->color = color; };

float Shape::get_angle() const { return angle; };

void Shape::set_angle(float angle) { this->angle = angle; };

Shape::Shape(Color color, float angle)
    : color{color}, angle{angle} {};
