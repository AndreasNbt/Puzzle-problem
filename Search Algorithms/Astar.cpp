// The A* algorithm.

#include "../State.h"

State* Astar(State *initial,unsigned long long &examined,unsigned long long &mem) {
    std::priority_queue<State*, std::vector<State *>, myComparator > frontier;
    std::unordered_map<long int, State *> closed;

    frontier.push(initial);
    examined = 0;
    mem = 1;
    while (!frontier.empty()) {
        State *current = frontier.top();
        frontier.pop();
        if (frontier.size() + closed.size() > mem)
            mem = frontier.size() + closed.size();
        if (closed.count(current->getKey()) == 0) {
            examined++;
            if (current->isFinal())
                return current;
            std::pair<long int, State *> k(current->getKey(), current);
            closed.insert(k);
            std::vector<State *> children = current->expand();
            for (auto x : children)
                if (closed.count(x->getKey()) == 0) {
                    x->setHvalue(x->heuristic() + x->getDepth());
                    frontier.push(x);
                }
        }
    }
    return nullptr;
}

