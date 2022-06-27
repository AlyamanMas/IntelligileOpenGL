#ifndef POINT_H_
#define POINT_H_

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

namespace gdi {
struct GPoint {
  float x, y;

  string to_string() const {
    return "GPoint {x: "s + std::to_string(this->x) + ", y: "s +
           std::to_string(this->y) + "}";
  };
};
} // namespace gdi

#endif // POINT_H_
