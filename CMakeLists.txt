cmake_minimum_required(VERSION 2.6)
project(Tetris)

add_executable(Tetris
  main.cpp
  Game.cpp
  TextureManager.cpp  
  Block.cpp
  Stage.cpp
  )

target_link_libraries(Tetris SDL2 SDL2_image)

add_definitions("-Wall")
