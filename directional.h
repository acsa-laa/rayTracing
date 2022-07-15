//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_DIRECTIONAL_H
#define RAYTRACING_DIRECTIONAL_H

#include <string>
#include "vec3.h"
#include "light.h"
#include "math.h"


class DirectionalLight : public Light{
public:

    vec3 l;
    vec3 scale;
    vec3 from;
    vec3 to;
    vec3 world_center;
    float world_radius;

    DirectionalLight(std::string type, vec3 l, vec3 scale, vec3 from, vec3 to) : Light(type, from){
        this->type = type;
        this->l = l;
        this->scale = scale;
        this->from = from;
        this->to = to;
    }

    vec3 sample_Li(const Surfel& hit /*in*/, vec3 v, vec3 *wi);

    void preprocessLight( const struct RunningOptions& ro);
};

vec3 DirectionalLight::sample_Li(const Surfel& hit, vec3 v, vec3 *wi){
    vec3 l_ = from - to;
    l_ = normalize(l_);
    *wi = l;
    return l_;
}

void DirectionalLight::preprocessLight(const struct RunningOptions& ro){
    //ro.setar raio e centro da esfera;
}

#endif //RAYTRACING_DIRECTIONAL_H
