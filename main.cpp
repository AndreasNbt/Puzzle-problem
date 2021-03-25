#include <iostream>
#include "State.h"


State* DFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BestFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* Astar(State *initial,unsigned long long &examined,unsigned long long &mem);


int main() {

    int **b = new int*[3];
    for (int i=0;i<3;i++)
        b[i] = new int[3];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            b[i][j] = i*3 + j + 1;
    b[2][2] = 0;
    State *a = new State(b,2,2);
    a->printPuzzle();
    std::cout << a->isFinal() << std::endl;
    unsigned long long examined;
    unsigned long long mem;
    //State *c = DFS(a,examined,mem);

}
