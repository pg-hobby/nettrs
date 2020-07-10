cmake_minimum_required(VERSION 2.6)
project(Tetris)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_image REQUIRED SDL2_image>=2.0.0)

include_directories(SYSTEM
	${SDL2_INCLUDE_DIRS}
	${SDL2IMAGE_INCLUDE_DIRS}
)
add_executable(Tetris
  main.cpp
  Game.cpp
  TextureManager.cpp  
  Block.cpp
  Stage.cpp
  )
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES})

add_definitions("-Wall -g3")
