#pragma once
#include <math.h>

class Point {
    public:
    Point() {
        x = 0;
        y = 0;
    };
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    };
    double x,y;
};