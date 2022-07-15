//
// Created by acsa on 14/07/22.
//
#include "vec3.h"
#include "point2.h"
#include "primitive.h"

#ifndef RAYTRACING_SURFEL_H
#define RAYTRACING_SURFEL_H

class Primitive;

class Surfel{
public:
    vec3 p;        //!< Contact point.
    vec3 n;       //!< The surface normal.
    vec3 wo;      //!< Outgoing direction of light, which is -ray.
    float time;     //!< Time of contact.
    Point2 uv;     //!< Parametric coordinate (u,v) of the hit surface.
    Primitive *primitive=nullptr; //!< Pointer to the primitive.
    //std::shared_ptr<Bounds3> bound;

    Surfel() {}
    Surfel( const vec3&p,const vec3&n, const vec3&wo, float time,
            const Point2& uv, Primitive *pri )
            : p{p}, n{n}, wo{wo}, time{time}, uv{uv}, primitive{pri}
    {/* empty */};
};

#endif //RAYTRACING_SURFEL_H
