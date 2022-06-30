#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
using namespace std;

template <typename T> void display_hex(T &c);

// gdi::Color
int test_gdi_color();

// gdi::Drawable
#include "gdi/Drawable.hpp"
void print_points(gdi::Drawable &s);
int test_shapes();

// gdi::GObject
int test_gdi_gobject();

#endif // UTIL_H_
