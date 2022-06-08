#include "camera.h"

ray camera::generateRay(double u, double v) const {
    return ray();
}

camera::camera(const point3 &origin, const point3 &lowerLeftCorner, const vec3 &horizontal, const vec3 &vertical)
        : origin(origin), lower_left_corner(lowerLeftCorner), horizontal(horizontal), vertical(vertical) {}
