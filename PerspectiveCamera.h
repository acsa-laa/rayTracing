//
// Created by 70386312419 on 12/05/2022.
//

#ifndef RAYTRACING_PERSPECTIVECAMERA_H
#define RAYTRACING_PERSPECTIVECAMERA_H


#include "camera.h"

class PerspectiveCamera : public camera{
    ray generateRay(double u, double v) const override {
        //return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    }
};


#endif //RAYTRACING_PERSPECTIVECAMERA_H
