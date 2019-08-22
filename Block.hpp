#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.hpp"

#define BLOCK_HEIGHT 50
#define BLOCK_WIDTH  50


class Block{

  public:
    Block();
    ~Block();

    void move_block_right();
    void move_block_left();
    void move_block_downfast();
    void rotate_block();
    
    bool Dead(){return isDead;} 
    void render_block();

  private:
    int pos_x = 30;
    int pos_y = 0;
    bool isDead = false;
    SDL_Texture* block_texture; 

};
