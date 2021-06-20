#include "WindowManager.h"
#include "Elems/Line_DDA.h"
#include "Elems/Line_MP.h"
#include "Elems/Circle_MP.h"

void WindowManager::init() {
    
}

void WindowManager::pushElem(Drawable *elem) {
    elems->push_back(elem);
}

void WindowManager::popElem() {
    if (elems->empty()) {
        return;    //需要完善
    } else {
        Drawable *result = elems->at(elems->size() - 1);
        elems->pop_back();
        delete result;
        return;
    }
}

void WindowManager::clearAll() {
    elems->clear();
}

void WindowManager::drawAll() {
    for (Drawable* a : *elems) {
        a->draw();
    }
}

int WindowManager::size() {
    return elems->size();
}