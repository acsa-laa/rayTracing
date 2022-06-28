//
// Created by acsa on 20/05/22.
//

#include "sphere.h"
/*
Sphere::Sphere(point3 center, double radius, color col){
    this->center = center;
    this->radius = radius;
}*/

Sphere::Sphere(point3 center, double radius, Integrator* integrator){
    this->center = center;
    this->radius = radius;
    this->integrator = integrator;
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

color Sphere::getColor(){
    return this->material.getCol();
}

void Sphere::setColor(const color& col_){
    this->material.setCol(col_);
}

double Sphere::intersects(const ray &r) {
        vec3 oc = r.origin() - this->center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - this->radius*this->radius;
        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0) {
            return -1.0;
        } else {
            return (-half_b - sqrt(discriminant) ) / a;
        }
}

