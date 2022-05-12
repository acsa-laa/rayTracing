//
// Created by gabriel on 4/28/22.
//

#ifndef RT_PARCER_H
#define RT_PARCER_H

#include <string>
#include <iostream>
#include "tinyxml2.h"
#include "RunningOptions.h"


class Parser{
public:
    static RunningOptions parse();

    static void toString(RunningOptions& ro);
};

#endif //RT_PARCER_H