cmake_minimum_required(VERSION 3.30)
project(hunt)

set(CMAKE_CXX_STANDARD 20)

add_executable(hunt main.cpp
        MapArea.cpp
        MapArea.h
        MapAreaWithKey.cpp
        MapAreaWithKey.h
        MapAreaWithChest.cpp
        MapAreaWithChest.h
        MapAreaWithQuicksand.cpp
        MapAreaWithQuicksand.h
        MapAreaWithCoconuts.cpp
        MapAreaWithCoconuts.h
        MapAreaWithPlanks.cpp
        MapAreaWithPlanks.h
        Game.h
        Game.cpp)
