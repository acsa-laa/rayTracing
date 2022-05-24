//
// Created by acsa on 20/05/22.
//

#include "sphere.h"

Sphere::Sphere(point3 center, double radius, color col){
    this->center = center;
    this->radius = radius;
    this->col = col;
}

const point3 Sphere::getCenter() const {
    return this->center;
}
void Sphere::setCenter(const point3 &center_) {
    this->center = center_;
}

double Sphere::getRadius() const {
    return this->radius;
}

void Sphere::setRadius(double radius_) {
    this->radius = radius_;
}

bool Sphere::intersects(const ray& r){
    vec3 oc = r.origin() - this->center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - this->radius*this->radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant > 0);
};