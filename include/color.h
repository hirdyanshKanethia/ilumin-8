#ifndef COLOR_H
#define COLOR_H

#include "hittable.h"
#include "hittable_list.h"
#include "ray.h"
#include "vec3.h"

using color = vec3;

extern hittable_list world;
extern vec3 light_pos;

inline color ray_color(const ray &r) {
  hit_record rec;
  if (world.hit(r, interval(0, infinity), rec)) {
    vec3 light_dir = unit_vector(light_pos - rec.p);
    double diffuse = std::max(dot(light_dir, rec.normal), 0.0);

    // Apply yellow tint to the sphere
    return color(1.0, 1.0, 0.3) * diffuse;
  }

  // Background gradient
  vec3 unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

#endif
