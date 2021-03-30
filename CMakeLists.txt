cmake_minimum_required(VERSION 3.17)
project(_)

set(CMAKE_CXX_STANDARD 20)

add_executable(_ main.cpp State.cpp State.h "Search Algorithms/DFS.cpp" "Search Algorithms/BFS.cpp" "Search Algorithms/BestFS.cpp" "Search Algorithms/Astar.cpp" Timer.cpp Timer.h)