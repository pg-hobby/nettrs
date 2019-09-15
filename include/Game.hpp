#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include "Block.hpp"

#ifdef DEBUG
#define debug_game(str)                           \
  std::cout << "(" << __FILE__ << ":"             \
            << std::to_string(__LINE__) << "): "  \
            << __func__ << ":"                    \
            << str << std::endl;
#else
#define debug_game(str) do { } while (0)
#endif

class Game{
  public:
    SDL_Window *window;
    SDL_Renderer *renderer;

    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height,
              bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    Btype get_blocktype();
    bool runnig() {
      return isRunning;
    }

  private:
    bool isRunning;
};


