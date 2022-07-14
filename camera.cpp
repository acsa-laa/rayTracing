#include "camera.h"

ray camera::generateRay(double u, double v) const {
    return ray();
}

camera::camera(const point3 &origin, const vec3 &horizontal, const vec3 &vertical)
        : origin(origin), horizontal(horizontal), vertical(vertical) {}
