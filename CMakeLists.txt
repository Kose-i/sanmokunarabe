cmake_minimum_required(VERSION 2.8.0)
project(sanmokunarabe)

#Pattern match

include_directories(PatternMatch/include)

add_executable(PatternMatch_make_file
  PatternMatch/src/PatternMatch_make_board.cpp
)

add_executable(PatternMatch_main
  PatternMatch/src/PatternMatch_main.cpp
)

#UCB1 algorithm

#include_directories(UCB1_algorithm/include)
#
#add_executable(UCB1_algorithm
#  UCB1_algorithm/src/main.cpp
#  UCB1_algorithm/src/sanmokunarabe.cpp
#  UCB1_algorithm/src/UCB1.cpp
#  UCB1_algorithm/src/Hand_sanmokunarabe.cpp
#  UCB1_algorithm/src/Computer_sanmokunarabe.cpp
#)

#epsillon greedy

include_directories(Epsillon_greedy/include)

add_executable(Epsillon_greedy
  Epsillon_greedy/src/main_epsillon.cpp
  Epsillon_greedy/src/sanmokunarabe_epsillon.cpp
  Epsillon_greedy/src/UCB1_epsillon.cpp
  Epsillon_greedy/src/Hand_sanmokunarabe_epsillon.cpp
  Epsillon_greedy/src/Computer_sanmokunarabe_epsillon.cpp
)
