#pragma once

#include <vector>
#include "Elems/Drawable.h"

class WindowManager {
    public:
    WindowManager() {
        elems = new std::vector<Drawable*>();
    };
    ~WindowManager() {
        delete elems;
    };
    void init();
    void pushElem(Drawable *elem);
    void popElem();
    void clearAll();
    void drawAll();
    int size();
    
    private:
    std::vector<Drawable*> *elems;
};