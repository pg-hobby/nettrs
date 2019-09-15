#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.hpp"
#include <iostream>
#include <string>

#define BLOCK_HEIGHT 50
#define BLOCK_WIDTH  50
#define BLOCK_COUNT   4
#define BLOCK_PATHSIZE 31

#ifdef DEBUG
#define debug(str)                                \
  std::cout << "(" << __FILE__ << ":"             \
            << std::to_string(__LINE__) << "): "  \
            << __func__ << ":"                    \
            << str << std::endl;
#else
#define debug(str) do { } while (0)
#endif

enum Btype{
  BLOCK_I,
  BLOCK_J,
  BLOCK_L,
  BLOCK_O,
  BLOCK_Z,
  BLOCK_S,
  BLOCK_T,
  BLOCK_SI,
  BLOCK_SL,
  BLOCK_MAX,
};

struct point {
  unsigned int x;
  unsigned int y;
};

struct mino {
  char name;
  char path[BLOCK_PATHSIZE];
  point p[BLOCK_COUNT];
};

class Block{

  public:
    Block(Btype btype, SDL_Renderer *ren);
    ~Block();

    void move_block_right();
    void move_block_left();
    void move_block_downfast(bool is_occupied);
    void rotate_block();
    bool Dead() {
      return isDead;
    }
    void render_block(SDL_Renderer *ren);
    int get_block_x(int i);
    int get_block_y(int i);
    SDL_Texture *get_block_texture() {
      return block_texture;
    }
    SDL_Rect get_block_Rect(int i) {
      return blocks[i];
    }

  private:
    bool isDead = false;
    SDL_Rect blocks[BLOCK_COUNT];
    SDL_Texture *block_texture;

    void init_block(int x, int y, int w, int h);
    void set_block(int x, int y, int w, int h, Btype type, SDL_Renderer *ren);
};
