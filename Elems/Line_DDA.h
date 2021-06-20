#pragma once

#include "Elems/Drawable.h"
#include "Elems/Point.h"

#define LINE_DDA_COLOR 0.5f, 1.0f, 0.5f

class Line_DDA : public Drawable {
    public:
    Line_DDA(Point first, Point second): p1(first), p2(second) {};
    void draw();
    private:
    Point p1, p2;
};