#include "../State.h"

State* BFS(State *initial,unsigned long long &examined,unsigned long long &mem) {
    std::queue<State *> frontier;
    std::unordered_map<long int, State *> closed;

    frontier.push(initial);
    examined = 0;
    mem = 1;
    while (!frontier.empty()) {
        State *current = frontier.front();
        frontier.pop();
        if (frontier.size() + closed.size() > mem)
            mem = frontier.size() + closed.size();
        if (closed.count(current->getKey()) == 0) {
            examined++;
            if (current->isFinal())
                return current;
            std::pair<long int, State *> k(current->getKey(), current);
            closed.insert(k);
            current->printPuzzle();
            std::vector<State *> children = current->expand();
            for (auto x : children) {
                if (closed.count(x->getKey()) == 0) {
                    frontier.push(x);
                    std::cout << "child went in:\n";
                    x->printPuzzle();
                }
            }
        }
        else {
            std::cout << "Found\n";
            current->printPuzzle();
            std::cout << "Equal to this:\n";
            closed.find(current->getKey())->second->printPuzzle();
        }
        std::cout << "============\n";
    }
    std::cout << examined << std::endl;
    return nullptr;
}