//
// Created by marti on 28/04/2022.
//

#ifndef RAYTRACING_FILM_H
#define RAYTRACING_FILM_H

#include <fstream>
#include "color.hpp"
#include "ray.hpp"

class film{
public:
    int image_width;
    int image_height;

    film(int imageWidth, int imageHeight) : image_width(imageWidth), image_height(imageHeight) {}

    virtual ~film() = default;

    void render(double aspect_ratio ) const{
        std::string filename="output-image.ppm";
        std::fstream fs (filename, std::fstream::out);
        if (!fs)
            std::cout << "Error loading file\n";

        fs << "P3\n" << image_width << " " << image_height << "\n" << "255\n" ;

        auto viewport_height = 2.0;
        auto viewport_width = aspect_ratio * viewport_height;
        auto focal_length = 1.0;
        auto origin = point3(0, 0, 0);
        auto horizontal = vec3(viewport_width, 0, 0);
        auto vertical = vec3(0, viewport_height, 0);
        auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

        for (int j = image_height-1; j >= 0; --j) {
            for (int i = 0; i < image_width; ++i) {
                auto u = double(i) / (image_width-1);
                auto v = double(j) / (image_height-1);
                ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
                color pixel_color = ray::ray_color(r, color(1,0,0), color(0, 1, 0), color(0,0,1), color(1, 1, 0));
                write_color(fs, pixel_color);
            }
        }
    }
};

#endif //RAYTRACING_FILM_H
