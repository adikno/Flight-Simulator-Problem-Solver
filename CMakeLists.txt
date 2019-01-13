cmake_minimum_required(VERSION 3.12)
project(untitled14)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)
add_executable(untitled14 FileCacheManger.cpp FileCacheManger.h CacheManager.h ClientHandler.h SerialServer.cpp SerialServer.h Server.h Solver.h GeneralClientHandler.cpp Main.cpp Main.h OpenSocket.cpp StringReverser.cpp StringReverser.h Searcher.h Searchable.h "State .h" BestFirstSearch.h BFS.h DFS.h Matrix.cpp Matrix.h Point.cpp SearcherSolver.h MatrixHandler.cpp MatrixHandler.h GeneralClientHandler.h ParallelServer.cpp ParallelServer.h MyParams.h)