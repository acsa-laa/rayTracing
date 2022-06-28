//
// Created by 70386312419 on 12/05/2022.
//

#ifndef RT_PARCER_H
#define RT_PARCER_H

#include <string>
#include "tinyxml2.h"
#include <iostream>
#include <vector>
#include "RunningOptions.h"
#include "sphere.h"
#include "flatIntegrator.h"
#include "dephMathIntegrator.h"
#include "normalIntegrator.h"


class Parser{
public:
    static struct RunningOptions parse();

};

#endif //RT_PARCER_H