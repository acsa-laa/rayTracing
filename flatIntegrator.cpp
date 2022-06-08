//
// Created by acsa on 07/06/22.
//

#include "flatIntegrator.h"

color ray_color(const ray &r, const struct RunningOptions &ro){
    for (auto shape: ro.objects) {
        if (shape->intersects(r) > 0.0) {
            return shape->getMaterial().getCol() / 255;
            }
    }
    vec3 unit_direction;
    if (std::strcmp(ro.cameraType.c_str(), "orthographic") == 0)
        unit_direction = unit_vector(r.origin());
    else
        unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    color c1 = (1.0 - t) * ro.backgroundBl / 255 + t * ro.backgroundTr / 255;
    color c2 = (1.0 - t) * ro.backgroundBr / 255 + t * ro.backgroundTl / 255;
    auto h = 0.5 * (unit_direction.x() + 1.0);
    return (1.0 - h) * c1 + h * c2;
}
