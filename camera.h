#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H


#include "vec3.h"
#include "film.h"
#include "ray.h"

class camera {
private:
    std::string type;
    double aspect_ratio;
    double viewport_height;
    double viewport_width;
    double focal_length;

    point3 origin;
    vec3 horizontal;
    vec3 vertical;
    vec3 lower_left_corner;
public:
    camera(const std::string &type, double aspectRatio, double viewportHeight, double viewportWidth, double focalLength,
           const point3 &origin, const vec3 &horizontal, const vec3 &vertical, const vec3 &lowerLeftCorner,
           const film &film);

private:

    film film;
public:
    ray generate_ray(int x, int y);

    const class film &getFilm() const;

    void setFilm(const class film &film);

    virtual ~camera();

    void render();

    double getAspectRatio() const;

    void setAspectRatio(double aspectRatio);

    double getViewportHeight() const;

    void setViewportHeight(double viewportHeight);

    double getViewportWidth() const;

    void setViewportWidth(double viewportWidth);

    double getFocalLength() const;

    void setFocalLength(double focalLength);

    const point3 &getOrigin() const;

    void setOrigin(const point3 &origin);

    const vec3 &getHorizontal() const;

    void setHorizontal(const vec3 &horizontal);

    const vec3 &getVertical() const;

    void setVertical(const vec3 &vertical);

    const vec3 &getLowerLeftCorner() const;

    void setLowerLeftCorner(const vec3 &lowerLeftCorner);
};


#endif //RAYTRACING_CAMERA_H