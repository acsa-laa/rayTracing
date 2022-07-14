//
// Created by acsa on 20/05/22.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include <iostream>
#include "primitive.h"
#include "Integrator.h"

class Sphere : public Primitive{
private:
    point3 center;
    double radius;
public:

    //Sphere(point3 center, double radius, color col);

    Sphere(point3 center, double radius, Integrator* integrator);

    const point3 getCenter() const ;

    void setCenter(const point3 &center_) ;

    double getRadius() const ;

    void setRadius(double radius_);

    double intersects(const ray& r) override;

    color getColor() override;

    void setColor(const color &col_) override;
};
#endif //RAYTRACING_SPHERE_H
