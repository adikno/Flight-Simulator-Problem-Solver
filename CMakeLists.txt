cmake_minimum_required(VERSION 3.12)
project(untitled14)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled14 FileCacheManger.cpp FileCacheManger.h CacheManager.h ClientHandler.h MySerialServer.cpp MySerialServer.h Server.h Solver.h MyTestClientHandler.cpp Main.cpp Main.h OpenSocket.cpp StringReverser.cpp StringReverser.h)