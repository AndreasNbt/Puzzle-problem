#include "../State.h"

State* DFS(State *initial,unsigned long long &examined,unsigned long long &mem) {
    std::stack<State *> frontier;
    std::vector<State> closed;

    frontier.push(initial);
    examined = 0;
    mem = 1;
    while (!frontier.empty()) {
        State *current = frontier.top();
        frontier.pop();
        if (frontier.size() + closed.size() > mem)
            mem = frontier.size() + closed.size();
        if (std::find(closed.begin(), closed.end(),*current) == closed.end()) {
            examined++;
            if (current->isFinal())
                return current;
            closed.push_back(*current);
            std::vector<State *> children = current->expand();
            for (auto x : children)
                if (std::find(closed.begin(), closed.end(),*x) == closed.end())
                    frontier.push(x);

        }
    }
    return nullptr;
}
