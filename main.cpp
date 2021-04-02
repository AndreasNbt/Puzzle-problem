// In this file, all the search algorithms are called and the results are printed on the console.


#include <iostream>
#include "State.h"
#include "Timer.h"

State* DFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* BestFS(State *initial,unsigned long long &examined,unsigned long long &mem);
State* Astar(State *initial,unsigned long long &examined,unsigned long long &mem);


int main() {
    int b[WIDTH*HEIGHT] = {3,6,8,2,1,0,7,4,5};
    auto *a = new State(b);

    unsigned long long examined;
    unsigned long long mem;

    Timer timer;

    timer.start();
    State *c = DFS(a, examined, mem);
    timer.stop();
    double mss = timer.getElapsedMicroSeconds();

    std::cout << "DFS\n";
    if (c!=nullptr) {
        std::cout << "Solution found with:\n" << "  Solution depth = " << c->getDepth() << ",\n  Maximum states stored in memory: " << mem << ",\n  States examined: " << examined << ",\n  In "<< mss<< " microseconds." <<std::endl;
    }
    else
        std::cout << "Problem was unsolvable\n";



    std::cout << "============\n";

    timer.start();
    State *d = BFS(a, examined, mem);
    timer.stop();
    double ms = timer.getElapsedMicroSeconds();

    std::cout << "BFS\n";
    if (d!=nullptr) {
        std::cout << "Solution found with:\n" << "  Solution depth = " << d->getDepth() << ",\n  Maximum states stored in memory: " << mem << ",\n  States examined: " << examined << ",\n  In "<< ms << " microseconds." <<std::endl;
    }
    else
        std::cout << "Problem was unsolvable\n";


    std::cout << "============\n";

    timer.start();
    State *e = BestFS(a, examined, mem);
    timer.stop();
    double ms2 = timer.getElapsedMicroSeconds();

    std::cout << "BestFS\n";
    if (e!=nullptr) {
        std::cout << "Solution found with:\n" << "  Solution depth = " << e->getDepth() << ",\n  Maximum states stored in memory: " << mem << ",\n  States examined: " << examined << ",\n  In "<< ms2 << " microseconds." <<std::endl;
    }
    else
        std::cout << "Problem was unsolvable\n";


    std::cout << "============\n";

    timer.start();
    State *f = Astar(a, examined, mem);
    timer.stop();
    double ms3 = timer.getElapsedMicroSeconds();

    std::cout << "A*\n";
    if (f!=nullptr) {
        std::cout << "Solution found with:\n" << "  Solution depth = " << f->getDepth() << ",\n  Maximum states stored in memory: " << mem << ",\n  States examined: " << examined << ",\n  In "<< ms3 << " microseconds." <<std::endl;
    }
    else
        std::cout << "Problem was unsolvable\n";

}
