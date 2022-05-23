//
// Created by 70386312419 on 12/05/2022.
//

#ifndef RT_PARCER_H
#define RT_PARCER_H

#include <string>
#include "tinyxml2.h"
#include "primitive.h"
#include <iostream>

struct RunningOptions{
    std::string cameraType;
    std::string filmType;
    int filmX_res = 0;
    int filmY_res = 0;
    std::string filmFilename;
    std::string filmImgtype;
    std::string backgroundType;
    std::string backgroundMapping;
    color backgroundColor = color(0,0,0);
    color backgroundBl = color(0,0,0);
    color backgroundBr = color(0,0,0);
    color backgroundTl = color(0,0,0);
    color backgroundTr = color(0,0,0);
} ;

class Parser{
public:
    static struct RunningOptions parse();

};

#endif //RT_PARCER_H