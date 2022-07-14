//
// Created by acsa on 07/06/22.
//

#ifndef RAYTRACING_DEPHMATHINTEGRATOR_H
#define RAYTRACING_DEPHMATHINTEGRATOR_H


#include "Integrator.h"
#include "parser.h"

class DepthMapIntegrator : public Integrator{
public:
    color ray_color(const ray &r, const struct RunningOptions &ro) override;
};

#endif//RAYTRACING_DEPHMATHINTEGRATOR_H