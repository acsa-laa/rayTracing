//
// Created by acsa on 07/06/22.
//

#ifndef RAYTRACING_NORMALINTEGRATOR_H
#define RAYTRACING_NORMALINTEGRATOR_H
#include "integrator.h"


class NormalIntegrator : public Integrator{
public:
    color ray_color(const ray& r, const struct RunningOptions& ro) override;
};

#endif //RAYTRACING_NORMALINTEGRATOR_H
