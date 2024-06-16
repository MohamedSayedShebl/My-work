cmake_minimum_required(VERSION 3.26)
project(p2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(p2
        BoardGame_Classes.hpp
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        main.cpp
        X_O_Board.cpp
        pyramid_XO.cpp
        five_tic_tac_toe_Board.cpp
        four_in_a_row_Board.cpp
)
