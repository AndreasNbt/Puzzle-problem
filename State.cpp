#include "State.h"

#include <random>

State::State() {
    int puzzle1d[WIDTH*HEIGHT];
   for (int i=0;i<WIDTH*HEIGHT-1;i++)
       puzzle1d[i] = i+1;
   puzzle1d[WIDTH*HEIGHT-1] = 0;

   std::shuffle(std::begin(puzzle1d),std::end(puzzle1d), std::mt19937(std::random_device()()));

   puzzle2d = new int*[WIDTH];
   for (int i=0;i<WIDTH;i++)
       puzzle2d[i] = new int[HEIGHT];
   for (int i=0;i<WIDTH;i++)
       for (int j=0;j<HEIGHT;j++) {
           puzzle2d[i][j] = puzzle1d[i*WIDTH + j];
           if (puzzle2d[i][j] == 0) {
               bX = i;
               bY = j;
           }
       }
}

State::State(int **puzzle, int x, int y) {
    puzzle2d = puzzle;
    bX = x;
    bY = y;
}


void State::printPuzzle() {
    for (int i=0;i<WIDTH;i++) {
        for (int j = 0; j < HEIGHT; j++) {
            std::cout << puzzle2d[i][j] << " ";
        }
        std::cout << "\n";
    }
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
    actionName = name;
}

void State::swapPieces(int x1, int y1, int x2, int y2) {
    int temp = puzzle2d[x1][y1];
    puzzle2d[x1][y1] = puzzle2d[x2][y2];
    puzzle2d[x2][y2] = temp;
}
State::State(State& other) {
    this->bX = other.getbX();
    this->bY = other.getbY();
    this->prev = other.getPrev();
    this->actionName = other.getActionName();
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            this->puzzle2d[i][j] = other.getPuzzlePiece(i,j);
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

int **State::getPuzzle2D() const {
    return puzzle2d;
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
    bool flag = true;
    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            if (puzzle2d[i][j] != (i*WIDTH + j + 1) && (i!=WIDTH-1 && j!=HEIGHT-1))
                flag = false;
    if (puzzle2d[WIDTH-1][HEIGHT-1])
        flag = false;
    return flag;

}


