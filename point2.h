//
// Created by acsa on 14/07/22.
//

#ifndef RAYTRACING_POINT2_H
#define RAYTRACING_POINT2_H

class Point2{
public:
    int u;
    int v;

    Point2(int u = 0, int v = 0) : u{u}, v{v} {};
    ~Point2() = default;
};

#endif //RAYTRACING_POINT2_H
