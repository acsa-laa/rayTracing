//
// Created by 70386312419 on 12/05/2022.
//

#include "PerspectiveCamera.h"

ray PerspectiveCamera::generateRay(double u, double v) const {
    return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}

PerspectiveCamera::PerspectiveCamera(double aspectRatio, double viewportHeight, double viewportWidth,
                                     double focalLength) : camera(aspectRatio, viewportHeight, viewportWidth, focalLength) {}

