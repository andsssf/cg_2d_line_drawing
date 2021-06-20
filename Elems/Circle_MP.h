#pragma once

#include "Elems/Drawable.h"
#include "Elems/Point.h"

#define CIRCLE_MP_COLOR 0.8f, 0.6f, 0.5f

class Circle_MP : public Drawable {
    public:
    Circle_MP(Point center, double radius): center(center), radius(radius) {};
    void draw();
    private:
    inline void drawOtherPoints(Point p);
    Point center;
    double radius;
};