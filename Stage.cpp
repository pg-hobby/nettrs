#include "Stage.hpp"
#include "Block.hpp"
#include "TextureManager.hpp"

#include <iostream> 

Stage::Stage(){
  std::cout << "Stage () " << std::endl;
  memset(grid,0,sizeof(grid));
  memset(grid_color,0,sizeof(grid_color));
  memset(grid_block,0,sizeof(grid_block));
}

Stage::~Stage(){
  std::cout << "~Stage() " << std::endl;
}

void Stage::render_stage(SDL_Renderer *ren){
  int i,j = 0;
  for(i=0;i<STAGE_WIDTH;i=i+BLOCK_WIDTH){
    for(j=0;j<STAGE_HEIGHT;j=j+BLOCK_HEIGHT){
      if(grid[i][j])SDL_RenderCopy(ren,grid_color[i][j],NULL,&grid_block[i][j]);
    }
  }
}

void Stage::move_stagecolor_down(){
  int x=0;
  int y=0;
  for(y=STAGE_HEIGHT-BLOCK_HEIGHT;y>=0;y=y-BLOCK_HEIGHT){
    for(x=0;x<STAGE_WIDTH;x=x+BLOCK_WIDTH){
      grid[x][y]       = grid[x][y-BLOCK_HEIGHT];
      grid_color[x][y] = grid_color[x][y-BLOCK_HEIGHT];
    }
  }
}

bool Stage::check_row(int row){
  int i=0;
  for(i=0;i<STAGE_WIDTH;i=i+BLOCK_WIDTH){
    if(!grid[i][row-BLOCK_HEIGHT]){  
      return false;
    } 
  } 
  return true;
}

void Stage::update_grid_status(int x, int y){
  grid[x][y] = true;
}

void Stage::copy_block_color(Block* block){
  int x = block -> get_block_x();
  int y = block -> get_block_y();
  if(grid[x][y]){
    grid_color[x][y] = block->get_block_texture();
    grid_block[x][y] = block->get_block_Rect();
  }
}

bool Stage::get_grid_status(int x, int y){
  return grid[x][y];
}

