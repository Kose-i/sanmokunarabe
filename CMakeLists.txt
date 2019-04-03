cmake_minimum_required(VERSION 2.8.0)
project(sanmokunarabe)

#pattern match

add_executable(PatternMatch_make_file
  src/PatternMatch_make_board.cpp
)

add_executable(PatternMatch_main
  src/PatternMatch_main.cpp
)

#UCB1 algorithm
add_executable(UCB1_main
  src/UCB1_main.cpp
)

include_directories(UCB1_algorithm/include)

add_executable(UCB1_algorithm
  UCB1_algorithm/src/main.cpp
  UCB1_algorithm/src/UCB1.cpp
  UCB1_algorithm/src/Hand_sanmokunarabe.cpp
  UCB1_algorithm/src/Computer_sanmokunarabe.cpp
)
