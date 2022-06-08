#ifndef COLOR_H
#define COLOR_H

#include <vector>

static color ray_color(const ray &r, color tr, color tl, color br, color bl) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    color c1 = (1.0-t)*br + t*tr;
    color c2 = (1.0-t)*bl + t*tl;
    auto h = 0.5*(unit_direction.x() + 1.0);
    return (1.0-h)*c1 + h*c2;
};

static color ray_color(const ray &r){
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
};
/*
static color ray_color(const ray &r, const std::vector<Primitive*> shapes, color tr, color tl, color br, color bl) {
    for (auto shape: shapes) {
        if (shape->intersects(r)) {
            return shape->getColor();
            //return color(1, 0, 0);
        }
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    color c1 = (1.0-t)*bl + t*tr;
    color c2 = (1.0-t)*br + t*tl;
    auto h = 0.5*(unit_direction.x() + 1.0);
    return (1.0-h)*c1 + h*c2;
};*/

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
};
#endif