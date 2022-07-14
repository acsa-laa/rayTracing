//
// Created by acsa on 07/06/22.
//

#ifndef RAYTRACING_FLATINTEGRATOR_H
#define RAYTRACING_FLATINTEGRATOR_H



#include <cstring>
#include "Integrator.h"
#include "parser.h"

class FlatIntegrator : public Integrator {
public:
    color ray_color(const ray &r, const struct RunningOptions &ro) override;
};


#endif //RAYTRACING_FLATINTEGRATOR_H
