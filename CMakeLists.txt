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
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wconversion -Wdisabled-optimization -Wendif-labels -Wfloat-equal -Winit-self -Winline -Wlogical-op -Wmissing-include-dirs -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo -Wswitch-default -Wswitch-enum -Wunsafe-loop-optimizations -Wvariadic-macros -Wwrite-strings ")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -march=native")
