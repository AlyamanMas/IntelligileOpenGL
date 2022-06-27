#include "Color.hpp"
using namespace gdi;

////////////////////////////////////////
////  ARGB  ////////////////////////////
////////////////////////////////////////

// ColorARGB::ColorARGB(){};

// DONE TESTING
ColorARGB::ColorARGB(uint8_t red, uint8_t green, uint8_t blue)
    : red{red}, green{green}, blue{blue} {};

// DONE TESTING
ColorARGB::ColorARGB(uint8_t red, uint8_t green, uint8_t blue,
                     uint8_t alpha_7bits)
    : red{red}, green{green}, blue{blue}, alpha{alpha_7bits} {};

// DONE TESTING
ColorARGB::ColorARGB(const ColorRGBA &in)
    : red{in.red}, green{in.green}, blue{in.blue}, alpha{in.alpha},
      type{in.type} {};

// DONE TESTING
bool ColorARGB::is_true_color() { return !this->type; };

////////////////////////////////////////
////  RGBA  ////////////////////////////
////////////////////////////////////////

// ColorRGBA::ColorRGBA(){};

ColorRGBA::ColorRGBA(uint8_t red, uint8_t green, uint8_t blue)
    : red{red}, green{green}, blue{blue} {};

ColorRGBA::ColorRGBA(uint8_t red, uint8_t green, uint8_t blue,
                     uint8_t alpha_7bits)
    : red{red}, green{green}, blue{blue}, alpha{alpha_7bits} {};

ColorRGBA::ColorRGBA(const ColorARGB &in)
    : red{in.red}, green{in.green}, blue{in.blue}, alpha{in.alpha},
      type{in.type} {};

bool ColorRGBA::is_true_color() { return !this->type; };
