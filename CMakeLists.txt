cmake_minimum_required(VERSION 3.12)
project(untitled14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled14
        AStar.h
        BestFirstSearch.h
        BFS.h
        CacheManager.h
        ClientHandler.h
        DFS.h
        FileCacheManger.cpp
        FileCacheManger.h
        GeneralClientHandler.cpp
        GeneralClientHandler.h
        Main.cpp
        Main.h
        Matrix.cpp
        Matrix.h
        MatrixHandler.cpp
        MatrixHandler.h
        MyParams.h
        OpenSocket.cpp
        ParallelServer.cpp
        ParallelServer.h
        Point.cpp
        Searchable.h
        Searcher.h
        SearcherSolver.h
        SerialServer.cpp
        SerialServer.h
        Server.h
        Solver.h
        "State .h"
        StringReverser.cpp
        StringReverser.h Task.h MatrixTask.h TasksQueue.cpp TasksQueue.h)
