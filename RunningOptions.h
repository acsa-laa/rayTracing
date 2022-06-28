//
// Created by marti on 11/05/2022.
//

#ifndef RAYTRACING_RUNNINGOPTIONS_H
#define RAYTRACING_RUNNINGOPTIONS_H

#include <iostream>
#include <vector>
#include "primitive.h"

struct RunningOptions{
    bool  help = false;
    std::string cameraType;
    int fovy = 1;
    std::vector<int> screen_window{1,1,1,1};
    std::vector<Primitive*> objects;
    std::string filmType;
    int filmX_res = 0;
    int filmY_res = 0;
    std::string filmFilename;
    std::string filmImgtype;
    std::string backgroundType = "color";
    std::string backgroundMapping = "screen";
    color backgroundColor = color(0,0,0);
    color backgroundBl = color(0,0,0);
    color backgroundBr = color(0,0,0);
    color backgroundTl = color(0,0,0);
    color backgroundTr = color(0,0,0);
    std::string integratorType;
};

#endif //RAYTRACING_RUNNINGOPTIONS_H
