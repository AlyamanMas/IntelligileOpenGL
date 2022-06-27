#include "util.hpp"

template <typename T> void display_hex(T &c) {
  void *p = &c;
  char *pp = reinterpret_cast<char *>(p);
  for (auto i = 0; i < sizeof(c); ++i) {
    printf("%02hhx ", *pp);
    ++pp;
  }
  cout << endl;
}

// gdi::Color
#include "gdi/Color.hpp"
using namespace gdi;
int test_gdi_color() {
  ColorARGB c1(0x21, 0x30, 0x1f);
  display_hex(c1);

  c1.type = 1;
  display_hex(c1);

  ColorARGB c2;
  display_hex(c2);

  ColorRGBA c3(c1);
  display_hex(c3);

  cout << c1.is_true_color() << endl;
  cout << c2.is_true_color() << endl;

  ColorRGBA c4(0x21, 0x30, 0x1f, 0b1011'1111);
  display_hex(c4);
  c4.type = 1;
  display_hex(c4);
  printf("%02x\n", c4.alpha);

  return 0;
}

// gdi::Drawable
#include "gdi/Drawable.hpp"
#include "shapes/Square.hpp"
using namespace shapes;

void print_points(gdi::Drawable &s) {
  cout << "printing points \n";
  int idx{0};
  for (auto i : s.provide_points()) {
    cout << "point " << idx << ": " << i.to_string() << endl;
    idx++;
  }
}

int test_shapes() {
  Rectangle r1(5, 10);

  print_points(r1);

  r1.set_height(7);

  print_points(r1);

  Square s1(2);
  print_points(s1);

  s1.set_height(5);
  print_points(s1);

  return 0;
}
