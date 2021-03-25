#include <iostream>
#include "State.h"


State* DFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BestFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* Astar(State *initial,unsigned long long &examined,unsigned long long &mem);


int main() {

    int b[WIDTH*HEIGHT] = {3,6,0,1,4,2,7,5,8};
    auto *a = new State(b,0,2);
    std::cout << a->isFinal() << std::endl;
    unsigned long long examined;
    unsigned long long mem;
    State *c = DFS(a,examined,mem);
    std::cout << examined;

}
