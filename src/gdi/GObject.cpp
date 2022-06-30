#include "GObject.hpp"
#include "Drawable.hpp"
#include "Point.hpp"
#include <stdexcept>
#include <vector>

using namespace std;
using namespace gdi;

void GObject::set_x(float x) { this->x = x; };
float GObject::get_x() const { return this->x; };
void GObject::set_y(float y) { this->y = y; };
float GObject::get_y() const { return this->y; };

void GObject::insert_drawable(const shared_ptr<Drawable> drawable) {
  this->content.push_back(drawable);
};

int GObject::delete_drawable(const shared_ptr<Drawable> drawable) {
  try {

    for (auto i = 0; i < this->content.size(); ++i) {
      const auto &elem = this->content.at(i);

      // equality test with raw pointer:
      // if (elem.get() == drawable.get()) {
      if (elem == drawable) {
        this->content.erase(this->content.begin() + i);
        return 0;
      }
    }
    return 1;

  } catch (...) {
    return 1;
  }
};

const vector<vector<GPoint>> GObject::get_drawables() const {
  vector<vector<GPoint>> drawables{};
  for (const auto &i : this->content) {
    vector<GPoint> gpoints{i->provide_points()};
    for (auto &j : gpoints) {
      j.x += this->get_x();
      j.y += this->get_y();
    }
    drawables.push_back(gpoints);
  }

  return drawables;
};

const vector<shared_ptr<Drawable>> &
GObject::get_original_drawables() const {
  return this->content;
};
