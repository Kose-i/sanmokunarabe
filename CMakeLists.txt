project(sanmokunarabe)

cmake_minimum_required(VERSION 2.8.0)

add_executable(make_file
  src/make_board.cpp
)
add_executable(main
  src/main.cpp
)
