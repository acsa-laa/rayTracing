//
// Created by marti on 11/05/2022.
//

#include "camera.h"
#include "ray.h"
#include "color.h"

camera::camera(double aspect_ratio, double viewportHeight, double viewportWidth, double focalLength, const point3 &origin,
               const vec3 &horizontal, const vec3 &vertical, const vec3 &lowerLeftCorner) : viewport_height(
        viewportHeight), viewport_width(viewportWidth), focal_length(focalLength), origin(origin),
                                                                                            horizontal(horizontal),
                                                                                            vertical(vertical),
                                                                                            lower_left_corner(
                                                                                                    lowerLeftCorner) {}
camera::camera(double aspect_ratio, double viewportHeight, double viewportWidth, double focalLength, const point3 &origin,
               const vec3 &horizontal, const vec3 &vertical, const vec3 &lowerLeftCorner, const class film &film) : viewport_height(
        viewportHeight), viewport_width(viewportWidth), focal_length(focalLength), origin(origin),
                                                                                            horizontal(horizontal),
                                                                                            vertical(vertical),
                                                                                            lower_left_corner(
                                                                                                    lowerLeftCorner), film(film) {}
camera::~camera() {

}

void camera::render(color bl, color br, color tl, color tr) {
    std::string filename="output-image.ppm";
    std::fstream fs (filename, std::fstream::out);
    if (!fs)
        std::cout << "Error loading file\n";

    fs << "P3\n" << film.getImageHeight() << " " << film.getImageHeight()<< "\n255\n";

    for (int j = film.getImageHeight()-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < film.getImageWidth(); ++i) {
            auto u = double(i) / (film.getImageWidth()-1);
            auto v = double(j) / (film.getImageHeight()-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray::ray_color(r, tr, tl, br, bl);
            write_color(fs, pixel_color);
        }

    }
    std::cerr << "\nDone.\n";
}

double camera::getViewportHeight() const {
    return viewport_height;
}

void camera::setViewportHeight(double viewportHeight) {
    viewport_height = viewportHeight;
}

double camera::getViewportWidth() const {
    return viewport_width;
}

void camera::setViewportWidth(double viewportWidth) {
    viewport_width = viewportWidth;
}

double camera::getFocalLength() const {
    return focal_length;
}

void camera::setFocalLength(double focalLength) {
    focal_length = focalLength;
}

const point3 &camera::getOrigin() const {
    return origin;
}

void camera::setOrigin(const point3 &origin) {
    camera::origin = origin;
}

const vec3 &camera::getHorizontal() const {
    return horizontal;
}

void camera::setHorizontal(const vec3 &horizontal) {
    camera::horizontal = horizontal;
}

const vec3 &camera::getVertical() const {
    return vertical;
}

void camera::setVertical(const vec3 &vertical) {
    camera::vertical = vertical;
}

const vec3 &camera::getLowerLeftCorner() const {
    return lower_left_corner;
}

void camera::setLowerLeftCorner(const vec3 &lowerLeftCorner) {
    lower_left_corner = lowerLeftCorner;
}

double camera::getAspectRatio() const {
    return aspect_ratio;
}

void camera::setAspectRatio(double aspectRatio) {
    aspect_ratio = aspectRatio;
}

const film &camera::getFilm() const {
    return film;
}

void camera::setFilm(const class film &film) {
    camera::film = film;
}

