//
// Created by marti on 28/04/2022.
//

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
    ray() = default;
    ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
    {}

    ray(const point3& origin, const vec3& direction, float tmin, float tmax) : orig(origin), dir(direction), tmin{tmin}, tmax{tmax} {/*empty*/}

    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }

public:
    point3 orig;
    vec3 dir;
    float tmin;
    float tmax;
};

#endif