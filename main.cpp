#include <iostream>
#include "State.h"
#include "Timer.h"

State* DFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BestFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* Astar(State *initial,unsigned long long &examined,unsigned long long &mem);


int main() {

    int b[WIDTH*HEIGHT] = {3,6,0,1,4,2,7,5,8};
    auto *a = new State(b,0,2);

    unsigned long long examined;
    unsigned long long mem;

    Timer timer;
    timer.start();
    State *d = BFS(a, examined, mem);
    timer.stop();
    double ms = timer.getElapsedMicroSeconds();


    if (d!=nullptr) {
        std::cout << "BFS\n";
        std::cout << "Solution found with:\n" << "  Solution depth = " << d->getDepth() << ",\n  Maximum states stored in memory: " << mem << ",\n  States examined: " << examined << ",\n  In "<< ms << " microseconds." <<std::endl;
    }
    else
        std::cout << "Problem was unsolvable\n";


    std::cout << "============\n";

    timer.start();
    State *e = BestFS(a, examined, mem);
    timer.stop();
    double ms2 = timer.getElapsedMicroSeconds();

    if (e!=nullptr) {
        std::cout << "BestFS\n";
        std::cout << "Solution found with:\n" << "  Solution depth = " << e->getDepth() << ",\n  Maximum states stored in memory: " << mem << ",\n  States examined: " << examined << ",\n  In "<< ms2 << " microseconds." <<std::endl;
    }
    else {
        std::cout << "Problem was unsolvable\n";
        std::cout << examined << " " << mem;
    }


}
