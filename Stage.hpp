#pragma once

#include "GameConfig.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Stage{

  public:
    Stage();
    ~Stage();

    bool grid[WIN_WIDTH/BLOCK_WIDTH][WIN_HEIGHT/BLOCK_HEIGHT]; //bool 1 -> occupied , 0 -> free
    SDL_Texture* grid_color[WIN_WIDTH/BLOCK_WIDTH][WIN_HEIGHT/BLOCK_HEIGHT]; 

    void render_stage();
    void move_stagecolor_down(); 
    bool check_row(int row);

    void copy_block_color();
  private:

};
