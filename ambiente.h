//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_AMBIENTE_H
#define RAYTRACING_AMBIENTE_H

#include <string>
#include "vec3.h"
//#include "../scene.hpp"
#include "light.h"

class Scene;

class AmbientLight : public Light{
public:

    vec3 l;

    AmbientLight(std::string type, vec3 l) : Light(type){
        this->type = type;
        this->l = l;
    }

    vec3 sample_Li(const Surfel& hit /*in*/, vec3 v, vec3 *wi);

};

vec3 AmbientLight::sample_Li(const Surfel& hit, vec3 v, vec3 *wi){
    return l;
}
#endif //RAYTRACING_AMBIENTE_H
