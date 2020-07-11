cmake_minimum_required(VERSION 2.6)
project(Tetris)

option(SDL2_STATIC "Static-linking of SDL2 libraries" OFF)

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
if(SDL2_STATIC)
	target_link_libraries(${PROJECT_NAME} "-Wl,-Bstatic -lSDL2_image -lSDL2  -Wl,-Bdynamic -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt -ljpeg -lpng -ltiff -lwebp")
else()
	target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES})
endif()

add_definitions("-Wall -g3")
