cmake_minimum_required(VERSION 2.6)
project(Tetris)

add_executable(Tetris
  src/main.cpp
  src/Game.cpp
  src/TextureManager.cpp  
  src/Block.cpp
  src/Stage.cpp
  )

include_directories(include)

target_link_libraries(Tetris SDL2 SDL2_image)

add_definitions("-Wall -g3")
