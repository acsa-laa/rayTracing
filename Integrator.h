//
// Created by acsa on 07/06/22.
//

#ifndef RAYTRACING_INTEGRATOR_H
#define RAYTRACING_INTEGRATOR_H

#include "ray.h"
#include "parser.h"

class Integrator {

public:
    virtual color ray_color(const ray& r, const struct RunningOptions& ro)  = 0;
};



#endif //RAYTRACING_INTEGRATOR_H