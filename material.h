//
// Created by acsa on 07/06/22.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include <string>
#include <utility>
#include "color.h"

class Material{
private:
    std::string type;
    color col;
public:

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
};

#endif //RAYTRACING_MATERIAL_H
