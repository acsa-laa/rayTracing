//
// Created by 70386312419 on 12/05/2022.
//

#ifndef RAYTRACING_ORTHOGRAPHICCAMERA_H
#define RAYTRACING_ORTHOGRAPHICCAMERA_H


#include "camera.h"

class OrthographicCamera : public camera {
public:
    OrthographicCamera(double aspect_ratio, double viewport_height,double viewport_width,double focal_length );
    ray generateRay(double u, double v) const override ;
};


#endif //RAYTRACING_ORTHOGRAPHICCAMERA_H
