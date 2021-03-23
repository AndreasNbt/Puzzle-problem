#include "State.h"

#include <random>

State::State(bool isFinal) {
   for (int i=0;i<WIDTH*HEIGHT-1;i++)
       puzzle1d[i] = i+1;
   puzzle1d[WIDTH*HEIGHT-1] = 0;

   if (!isFinal)
       std::shuffle(std::begin(puzzle1d),std::end(puzzle1d), std::mt19937(std::random_device()()));

   for (int i=0;i<WIDTH;i++)
       for (int j=0;j<HEIGHT;j++) {
           puzzle2d[i][j] = puzzle1d[i*WIDTH + j];
       }
   printPuzzle();
}

void State::printPuzzle() {
    for (int i=0;i<WIDTH;i++) {
        for (int j = 0; j < HEIGHT; j++) {
            std::cout << puzzle2d[i][j] << " ";
        }
        std::cout << "\n";
    }
}
