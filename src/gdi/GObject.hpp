#ifndef GOBJECT_H_
#define GOBJECT_H_

#include "Drawable.hpp"
#include "Point.hpp"

#include <memory>
#include <vector>

using namespace std;

namespace gdi {
class GObject {
  vector<shared_ptr<Drawable>> content{};
  float x{0}, y{0};

public:
  GObject(){};
  GObject(float x, float y) : x{x}, y{y} {};
  virtual ~GObject(){};

  void set_x(float x);
  float get_x() const;
  void set_y(float y);
  float get_y() const;

  void insert_drawable(const shared_ptr<Drawable> drawable);
  /// Returns 0 if successful, 1 otherwise
  int delete_drawable(const shared_ptr<Drawable> drawable);

  /// Return drawables, adding GObject's x and y to their vertices
  const vector<vector<GPoint>> get_drawables() const;
  /// Return drawables without GObject's x and y
  const vector<shared_ptr<Drawable>> &get_original_drawables() const;
};
} // namespace gdi

#endif // GOBJECT_H_
