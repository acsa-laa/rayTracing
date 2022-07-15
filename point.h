//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_POINT_H
#define RAYTRACING_POINT_H
#include <string>
#include "vec3.h"
#include "light.h"
//#include "../scene.hpp"


class PointLight : public Light{
public:

    vec3 i;
    vec3 scale;
    // vec3 from;

    PointLight(std::string type, vec3 i, vec3 scale, vec3 from) : Light(type, from){
        this->type = type;
        this->i = i;
        this->scale = scale;
        this->from = from;
    }

    vec3 sample_Li(const Surfel& hit /*in*/, vec3 v, vec3 *wi) {

        vec3 l = from - hit.p;
        l = normalize(l);
        *wi = i;
        return l;

    }

};

#endif //RAYTRACING_POINT_H
