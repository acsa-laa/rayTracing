//
// Created by gabriel on 4/28/22.
//

#ifndef RT_PARCER_H
#define RT_PARCER_H

#include <string>
#include <iostream>
#include "tinyxml2.h"

struct RunningOptions{
    std::string cameraType;
    std::string filmType;
    std::string filmX_res;
    std::string filmY_res;
    std::string filmFilename;
    std::string filmImgtype;
    std::string backgroundType;
    std::string backgroundMapping;
    std::string backgroundColor;
    std::string backgroundBl;
    std::string backgroundBr;
    std::string backgroundTl;
    std::string backgroundTr;
} RunningOptions;

class Parser{
public:
    static struct RunningOptions parse();

    static void toString(const struct RunningOptions& ro);
};

#endif //RT_PARCER_H