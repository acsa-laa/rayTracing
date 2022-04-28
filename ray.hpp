//
// Created by marti on 28/04/2022.
//

#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

class ray {
public:
    ray() {}
    ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
    {}

    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }

public:
    point3 orig;
    vec3 dir;


    static color ray_color(const ray& r, color tr, color tl, color br, color bl) {
        vec3 unit_direction = unit_vector(r.direction());
        auto t = 0.5*(unit_direction.y() + 1.0);
        color c1 = (1.0-t)*br + t*tr;
        color c2 = (1.0-t)*bl + t*tl;
        auto h = 0.5*(unit_direction.x() + 1.0);
        return (1.0-h)*c1 + h*c2;
    }
};

#endif