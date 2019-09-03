#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.hpp"
#include <iostream>
#include <string>

#define BLOCK_HEIGHT 50
#define BLOCK_WIDTH  50

#ifdef DEBUG
#define debug(str)                                \
  std::cout << "(" << __FILE__ << ":"             \
            << std::to_string(__LINE__) << "): "  \
            << __func__ << ":"                    \
            << str << std::endl;
#else
#define debug(str) do { } while (0)
#endif

class Block{

  public:
    Block(SDL_Renderer *ren);
    ~Block();

    void move_block_right();
    void move_block_left();
    void move_block_downfast(bool is_occupied);
    void rotate_block(); 
    bool Dead(){return isDead;} 
    void render_block(SDL_Renderer *ren);
    int  get_block_x();
    int  get_block_y();
    SDL_Texture* get_block_texture(){return block_texture;}
    SDL_Rect get_block_Rect(){return block;}

  private:
    bool isDead = false;
    SDL_Rect block;
    SDL_Texture* block_texture; 

};
