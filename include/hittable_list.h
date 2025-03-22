#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <vector>

class hittable_list : public hittable {
public:
  std::vector<hittable *> objects;

  void add(hittable *object) { objects.push_back(object); }

  bool hit(const ray &r, double ray_tmin, double ray_tmax,
           hit_record &rec) const override {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_tmax;

    for (const auto &object : objects) {
      if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
        hit_anything = true;
        closest_so_far = temp_rec.t;
        rec = temp_rec;
      }
    }

    return hit_anything;
  }
};

#endif
