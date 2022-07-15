//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

#include <string>
#include "surfel.h"
#include "vec3.h"
//#include "../scene.hpp"

class Scene;

class Light{
public:
    std::string type;
    vec3 from;

    Light(std::string type){this->type = type;}
    Light(std::string type, vec3 from){this->from = from; this->type = type;}
    virtual vec3 sample_Li(const Surfel& hit /*in*/, vec3 v, vec3 *wi) = 0;
    //void preprocessLight( Scene & scene) {};

};

#endif //RAYTRACING_LIGHT_H
