#include <iostream>
#include "State.h"


State* DFS(State *initial,long &examined, long &mem);
State* BFS(State *initial,long &examined, long &mem);
State* BestFS(State *initial,long &examined, long &mem);
State* Astar(State *initial,long &examined, long &mem);

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
