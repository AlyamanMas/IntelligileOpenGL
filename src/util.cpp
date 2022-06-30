#include "util.hpp"
#include "gdi/Point.hpp"
#include "shapes/Rectangle.hpp"
#include <cstdint>
#include <memory>

using namespace std;

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

// gdi::GObject
#include "gdi/GObject.hpp"

void print_gpoints(const vector<GPoint> &x) {
  uint32_t counter{0};
  for (auto &i : x) {
    cout << counter << ": " << i.to_string() << endl;
    ++counter;
  }
}

void print_drawables(const vector<vector<GPoint>> &x) {
  for (auto &i : x) {
    cout << endl;
    print_gpoints(i);
  }
  cout << endl;
}

int test_gdi_gobject() {
  GObject g1;
  shared_ptr<Drawable> r1(new Rectangle(5, 10));
  shared_ptr<Drawable> s1(new Square(2));

  g1.insert_drawable(r1);
  g1.insert_drawable(s1);

  cout << "Printing G1(0, 0): " << endl;
  print_drawables(g1.get_drawables());

  g1.set_x(5);
  g1.set_y(12);

  cout << "Printing G1(5, 12): " << endl;
  print_drawables(g1.get_drawables());

  return 0;
};
