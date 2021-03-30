#ifndef __STATE_H
#define __STATE_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

#define WIDTH 3
#define HEIGHT 3

class State {
    public:
        State();
        State(const int *puzzle,int x, int y);
        State(const State&) = default;
        ~State() = default;
        State(State&&) = default;
        State& operator=(const State& other);
        bool operator==(const State& other);
        [[nodiscard]] int getbX() const;
        [[nodiscard]] int getbY() const;
        [[nodiscard]] State* getPrev() const;
        [[nodiscard]] std::string getActionName() const;
        void setbX(int x);
        void setbY(int y);
        void setPrev(State*);
        void setActionName(std::string name);
        bool goUp(State&);
        bool goRight(State&);
        bool goLeft(State&);
        bool goDown(State&);
        std::vector<State *> expand();
        [[nodiscard]] int getPuzzlePiece(int x,int y) const;
        void swapPieces(int x1, int y1, int x2, int y2);
        bool isFinal();
        [[nodiscard]] long int getKey() const;
        int getDepth();
        int heuristic();
        [[nodiscard]] int getHvalue() const;
        void setHvalue(int value);
        void find(int value, int &x, int &y);
    private:
        int puzzle2d[WIDTH][HEIGHT]{};
        int bX, bY;
        State *prev;
        std::string actionName;
        int Hvalue;

    public:
        void printPuzzle();

};

class myComparator
{
public:
    int operator() (State *s1 , State *s2) const
    {
        return s1->getHvalue()>s2->getHvalue();
    }
};

#endif //__STATE_H
