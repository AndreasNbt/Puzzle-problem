#include <iostream>
#include "State.h"


int main() {

    State a;

    a.printPuzzle();
    std::cout << "==========" << std::endl;
    State child;
    a.goLeft(child);
    child.printPuzzle();
    std::cout << "==========" << std::endl;
    a.printPuzzle();
    std::cout << "==========" << std::endl;
    a.goRight(child);
    child.printPuzzle();
    std::cout << "==========" << std::endl;
    a.printPuzzle();

    return 0;
}
