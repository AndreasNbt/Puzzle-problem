// Implementation of the State class

#include "State.h"
#include <random>



State::State() {
    int puzzle1d[WIDTH*HEIGHT];
   for (int i=0;i<WIDTH*HEIGHT-1;i++)
       puzzle1d[i] = i+1;
   puzzle1d[WIDTH*HEIGHT-1] = 0;

   std::shuffle(std::begin(puzzle1d),std::end(puzzle1d), std::mt19937(std::random_device()()));

   for (int i=0;i<WIDTH;i++)
       for (int j=0;j<HEIGHT;j++) {
           puzzle2d[i][j] = puzzle1d[i*WIDTH + j];
           if (puzzle2d[i][j] == 0) {
               bX = i;
               bY = j;
           }
       }
    prev = nullptr;
    actionName = "";
}

State::State(const int *puzzle) {
    for (int i=0;i<WIDTH;i++)
        for (int j = 0; j < HEIGHT; j++) {
            puzzle2d[i][j] = puzzle[i*WIDTH+j];
            if (!(puzzle2d[i][j])) {
                bX = i;
                bY = j;
            }
        }
    prev = nullptr;
    actionName = "";
}

int State::getbX() const {
    return bX;
}

int State::getbY() const {

    return bY;
}

State *State::getPrev() const {
    return prev;
}

std::string State::getActionName() const{
    return actionName;
}

int State::getPuzzlePiece(int x, int y) const {
    return puzzle2d[x][y];
}

void State::setbX(int x) {
    bX = x;
}

void State::setbY(int y) {
    bY = y;
}

void State::setPrev(State *s) {
    prev = s;
}

void State::setActionName(std::string name) {
    actionName = std::move(name);
}

void State::swapPieces(int x1, int y1, int x2, int y2) {
    int temp = puzzle2d[x1][y1];
    puzzle2d[x1][y1] = puzzle2d[x2][y2];
    puzzle2d[x2][y2] = temp;
}

State& State::operator=(const State& other) {
    this->bX = other.getbX();
    this->bY = other.getbY();
    this->prev = other.getPrev();
    this->actionName = other.getActionName();
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            this->puzzle2d[i][j] = other.getPuzzlePiece(i,j);
}

bool State::goUp(State &s) {
    if (bX > 0) {
        s = *this;
        s.swapPieces(bX, bY, bX - 1, bY);
        s.setbX(bX-1);
        s.setActionName("Up");
        s.setPrev(this);
        return true;
    }
    return false;

}

bool State::goRight(State &s) {

    if (bY < WIDTH - 1) {
        s = *this;
        s.swapPieces(bX, bY, bX , bY+1);
        s.setbY(bY+1);
        s.setActionName("Right");
        s.setPrev(this);
        return true;
    }
    return false;

}

bool State::goLeft(State &s) {

    if (bY > 0) {
        s = *this;
        s.swapPieces(bX, bY, bX, bY-1);
        s.setbY(bY-1);
        s.setActionName("Left");
        s.setPrev(this);
        return true;
    }
    return false;

}

bool State::goDown(State &s) {

    if (bX < HEIGHT-1) {
        s = *this;
        s.swapPieces(bX, bY, bX + 1, bY);
        s.setbX(bX+1);
        s.setActionName("Down");
        s.setPrev(this);
        return true;
    }
    return false;

}

bool State::isFinal() {
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            if ((i==WIDTH-1 && j ==HEIGHT-1)) {
                if (puzzle2d[i][j] != 0) return false;
            } else {
                if (puzzle2d[i][j] != (i*WIDTH + j + 1)) return false;
            }
    return true;

}

std::vector<State *> State::expand() {

    std::vector<State *> children;
    State *child;

    child = new State(*this);


    if (goUp(*child)) {
        children.push_back(child);
    }
    else delete child;

    child = new State(*this);
    if (goRight(*child)) {
        children.push_back(child);
    }
    else delete child;

    child = new State(*this);
    if (goLeft(*child)) {
        children.push_back(child);
    }
    else delete child;

    child = new State(*this);
    if (goDown(*child)) {
        children.push_back(child);
    }
    else delete child;

    return children;

}

bool State::operator==(const State &other) {
    if (bX != other.bX || bY != other.bY)
        return false;
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            if (puzzle2d[i][j] != other.puzzle2d[i][j])
                return false;
    return true;
}

long int State::getKey() const {
    long int k = bX * 1000 + bY *10;
    int t = 1;
    for (int i = 0;i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            k += (puzzle2d[i][j] * t);
            t *= 10;
        }
    }
    return k;
}

int State::getDepth() {
    int depth = 0;
    State *p =  this;
    while (p != nullptr) {
        depth ++;
        p = p->prev;
    }
    return depth-1;
}

int State::heuristic() {
    int outOfRow = 0;
    int outOfColumn = 0;
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++) {
            int x,y;
            if (!(i==WIDTH-1 && j==HEIGHT-1)) {
                find(i * WIDTH + j + 1, x, y);
                if (i != x) outOfRow++;
                if (j != y) outOfColumn++;
            }
        }
    return outOfRow + outOfColumn;
}

int State::getHvalue() const {
    return Hvalue;
}

void State::setHvalue(int value) {
    Hvalue = value;
}

void State::find(int value, int &x, int &y) {
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            if (puzzle2d[i][j] == value) {
                x = i;
                y = j;
            }
    }

std::ostream & operator<<(std::ostream &stream,const State &a)
{
    std::string s="";

    s= a.getActionName();
    State *p=a.getPrev();

    while (p!=nullptr)
    {
        s = p->getActionName()+" "+s;
        p = p->getPrev();
    }
    stream <<s;
    return stream;
}
