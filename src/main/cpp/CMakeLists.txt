cmake_minimum_required(VERSION 3.4.1)

add_library(game SHARED
            src/main/cpp/game.cpp)

find_library(log-lib log)

target_link_libraries(game
                      ${log-lib})
