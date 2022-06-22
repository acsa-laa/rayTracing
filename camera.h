#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "film.h"
#include "ray.h"
class camera {
public:
     camera(double aspect_ratio, double viewport_height,double viewport_width,double focal_length ) {

        this->aspect_ratio = aspect_ratio;
        this->viewport_height = viewport_height;
        this->viewport_width = viewport_width;
        this->focal_length = focal_length;

        origin = point3(0, 0, 0);
        horizontal = vec3(viewport_width, 0.0, 0.0);
        vertical = vec3(0.0, viewport_height, 0.0);
        lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
    }

    camera(const point3 &origin, const point3 &lowerLeftCorner, const vec3 &horizontal, const vec3 &vertical);

    virtual ray generateRay(double u, double v) const ;

protected:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;

    double aspect_ratio;
    double viewport_height;
    double viewport_width;
    double focal_length;
};
#endif