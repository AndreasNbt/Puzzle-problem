#include <iostream>
#include "State.h"


int main() {

    State a;
    a.printPuzzle();
    std::vector<State*> p = a.expand();


    for (State* s : p) {
       s->printPuzzle();
        std::cout << "=========" << std::endl;
    }

    return 0;
}
