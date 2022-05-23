//
// Created by acsa on 20/05/22.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "primitive.h"

class Sphere : public Primitive{
private:
    point3 center;
    double radius;
    color col;
public:

    Sphere(point3 center, double radius, color col){
        this->center = center;
        this->radius = radius;
        this->col = col;
    }
    const point3 getCenter() const ;

    void setCenter(const point3 &center_) ;

    double getRadius() const ;

    void setRadius(double radius_);

    bool intersects(const ray& r) override;

};
#endif //RAYTRACING_SPHERE_H
