#include "WindowManager.h"
#include "Elems/Line/Line_DDA.h"

void WindowManager::init() {
    // 测试样例
    pushElem(new Line_DDA(Point(0, 0), Point(700, 450)));
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