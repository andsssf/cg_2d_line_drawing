#pragma once

#include "Elems/Drawable.h"
#include "Elems/Point.h"

#define LINE_MP_COLOR 0.2f, 1.0f, 0.7f

class Line_MP : public Drawable {
    public:
    Line_MP(Point first, Point second): p1(first), p2(second) {};
    void draw();
    private:
    Point p1, p2;
};