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
    void move_stagecolor_down(int row);
    bool check_row(int row);
    void update_grid_status(int x, int y);
    void copy_block_color(Block *block);
    bool get_grid_status(int x, int y);

  private:
    //bool 1 -> occupied , 0 -> free
    bool grid[WIN_WIDTH][WIN_HEIGHT];
    SDL_Texture *grid_color[WIN_WIDTH][WIN_HEIGHT];
    SDL_Rect grid_block[WIN_WIDTH][WIN_HEIGHT];
};
