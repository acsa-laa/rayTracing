//
// Created by 70386312419 on 12/05/2022.
//

#ifndef RT_PARCER_H
#define RT_PARCER_H

#include <string>
#include "tinyxml2.h"
#include <iostream>

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
} ;

class Parser{
public:
    static struct RunningOptions parse();

};

#endif //RT_PARCER_H