//
// Created by acsa on 07/06/22.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include <string>
#include "vec3.h"
#include "surfel.h"
#include "ray.h"

class Material{
private:
    std::string type;
    color col;
public:

    Material(){}

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type_) {
        this->type = type_;
    }

    const color &getCol() const {
        return col;
    }

    void setCol(const color &col_){
        this->col = col_;
    }
    virtual void scatter(Surfel * isect, ray *r) = 0;
    virtual vec3 kd() = 0;
};

#endif //RAYTRACING_MATERIAL_H
