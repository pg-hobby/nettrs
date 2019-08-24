#pragma once

#include "GameConfig.hpp"
#include "Block.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Stage{

  public:
    Stage();
    ~Stage();
    void render_stage(SDL_Renderer *ren);
    void move_stagecolor_down(); 
    bool check_row(int row);
    void update_grid_status(int x, int y);
    void copy_block_color(Block* block);

  private:

    bool grid[WIN_WIDTH/BLOCK_WIDTH][WIN_HEIGHT/BLOCK_HEIGHT]; //bool 1 -> occupied , 0 -> free
    SDL_Texture* grid_color[WIN_WIDTH/BLOCK_WIDTH][WIN_HEIGHT/BLOCK_HEIGHT]; 
    SDL_Rect grid_block[WIN_WIDTH/BLOCK_WIDTH][WIN_HEIGHT/BLOCK_HEIGHT];
};
