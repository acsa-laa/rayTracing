//
// Created by acsa on 20/05/22.
//

#ifndef RAYTRACING_PRIMITIVE_H
#define RAYTRACING_PRIMITIVE_H

#include "ray.h"

class Primitive{
protected:
    color col;
public:
    virtual bool intersects(const ray& ray) = 0;

    color getColor(){
        return this->col;
    }
    void setColor(const color& col_){
        this->col = col_;
    }

};

#endif //RAYTRACING_PRIMITIVE_H
