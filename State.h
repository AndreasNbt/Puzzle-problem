#ifndef __STATE_H
#define __STATE_H
#include <iostream>
#include <algorithm>

#define WIDTH 5
#define HEIGHT 5

class State {
    public:
        explicit State(bool isFinal);
    private:
        int puzzle1d[WIDTH*HEIGHT];
        int puzzle2d[WIDTH][HEIGHT];
        int bX, bY;
        State *prev;
        std::string actionName;

    private:
        void printPuzzle();

};


#endif //__STATE_H
