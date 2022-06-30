#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

// TODO: define index colors as an array of 256 colors

namespace gdi {

class ColorRGBA; // to solve circular dependency problem

class ColorARGB {
public:
  // NOTE: despite the order of alpha and type here being alpha then
  // type, the compiler starts ordering bitfield members from LSB to
  // MSB, so putting alpha before type results in left most bit being
  // type and the rest being alpha i.e. the default value for the
  // first byte is 0x7F instead of 0xFE.

  // default value 0x7F
  unsigned int alpha : 7 {0b1111111};
  // 0 for True Type and 1 for indexed
  unsigned int type : 1;
  uint8_t red, green, blue;

  ColorARGB(){};
  ColorARGB(uint8_t red, uint8_t green, uint8_t blue);
  // Size of alpha will be reduced to 7 bits
  ColorARGB(uint8_t red, uint8_t green, uint8_t blue,
            uint8_t alpha_7bits);
  ColorARGB(const ColorRGBA &in);
  ~ColorARGB(){};

  bool is_true_color();
};

class ColorRGBA {
public:
  uint8_t red, green, blue;
  unsigned int alpha : 7 {0b1111111};
  // 0 for True Type and 1 for indexed
  unsigned int type : 1;

  ColorRGBA(){};
  ColorRGBA(uint8_t red, uint8_t green, uint8_t blue);
  // Size of alpha will be reduced to 7 bits
  ColorRGBA(uint8_t red, uint8_t green, uint8_t blue,
            uint8_t alpha_7bits);
  ColorRGBA(const ColorARGB &in);
  ~ColorRGBA(){};

  bool is_true_color();
};
} // namespace gdi

#endif // COLOR_H_
