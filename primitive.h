//
// Created by acsa on 20/05/22.
//

#ifndef RAYTRACING_PRIMITIVE_H
#define RAYTRACING_PRIMITIVE_H


#include "material.h"
#include "Integrator.h"

class Primitive{
protected:
    Material material;
    Integrator* integrator;
public:
    virtual double intersects(const ray& ray) = 0;

    Integrator *getIntegrator() const {
        return integrator;
    }

    void setIntegrator(Integrator *integrator) {
        Primitive::integrator = integrator;
    }

    const Material getMaterial() const {
        return material;
    }

    void setMaterial(const Material &material) {
        Primitive::material = material;
    }
    virtual color getColor(){
        return this->material.getCol();
    }

    virtual void setColor(const color& col_){
        this->material.setCol(col_);
    }
};

#endif //RAYTRACING_PRIMITIVE_H
