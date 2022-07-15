//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_SPOT_H
#define RAYTRACING_SPOT_H
#include <string>
#include "vec3.h"
#include "light.h"
//#include "../scene.hpp"
#include "math.h"

class SpotLight : public Light{
public:

    vec3 i;
    vec3 scale;
    vec3 from;
    vec3 to;
    float cutoff;
    float falloff;

    SpotLight(std::string type, vec3 i, vec3 scale, vec3 from, vec3 to, float cutoff, float falloff) : Light(type){
        this->i = i;
        this->scale = scale;
        this->from = from;
        this->to = to;
        this->cutoff = cos((cutoff*M_PI)/180.0);
        this->falloff = cos((falloff*M_PI)/180.0);
    }

    void preprocessLight(Scene & scene){
    }

    vec3 sample_Li(const Surfel& hit /*in*/, vec3 v, vec3 *wi) {

        vec3 lightDir = from - hit.p;
        lightDir = normalize(lightDir);

        vec3 spotDir = to - from;
        spotDir = normalize(-spotDir);

        float theta = dot(lightDir, spotDir);///(magnitude(lightDir)*magnitude(spotDir));

        // float epsilon   = falloff - cutoff;
        // float intensity = std::min(1.0f, std::max(0.f, (theta - cutoff) / epsilon));

        // *wi = i * intensity;

        *wi = i * Falloff(theta);

        return lightDir;
    }

    float Falloff(float theta){
        float cosTheta = theta;

        if(cosTheta < cutoff)
            return 0.0;
        if(cosTheta > falloff)
            return 1.0;

        float delta = (cosTheta - cutoff) /
                      (falloff - cutoff);
        return (delta * delta) * (delta * delta);
    }
};

#endif //RAYTRACING_SPOT_H
