//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_BLINNPHONGINTEGRATOR_H
#define RAYTRACING_BLINNPHONGINTEGRATOR_H
#include "Integrator.h"
#include "parser.h"
#include "surfel.h"
#include "blinnMaterial.h"

class BlinnPhongIntegrator : public Integrator{
public:
    color ray_color(const ray &r, const struct RunningOptions &ro) override;
};
#endif //RAYTRACING_BLINNPHONGINTEGRATOR_H
