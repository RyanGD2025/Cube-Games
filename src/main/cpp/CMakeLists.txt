cmake_minimum_required(VERSION 3.10.2)
project("cubegames")

add_library(game SHARED
            src/main/cpp/game.cpp
            src/main/cpp/game_jni.cpp)

find_library(log-lib log)

target_link_libraries(game ${log-lib})
