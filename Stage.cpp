#include "Stage.hpp"
#include "Block.hpp"
#include "TextureManager.hpp"

#include <iostream> 

Stage::Stage(){
  std::cout << "Stage () " << std::endl;
  memset(grid,0,sizeof(grid));
  memset(grid_color,0,sizeof(grid_color));
  memset(grid_block,0,sizeof(grid_block));
  int i,j = 0;
  //std::cout << STAGE_WIDTH/BLOCK_WIDTH << " "  << STAGE_HEIGHT/BLOCK_HEIGHT << std::endl; 
  for(i=0;i<STAGE_WIDTH;i=i+BLOCK_WIDTH){
    for(j=0;j<STAGE_HEIGHT;j=j+BLOCK_HEIGHT){
      if(grid[i][j])std::cout << i <<" "<< j << " has non zero value"<<std::endl;
  //    std::cout << i << "," << j << std::endl;
  //    std::cout << grid[i][j] << std::endl;
    }
  }
}

Stage::~Stage(){
  std::cout << "~Stage() " << std::endl;
}

void Stage::render_stage(SDL_Renderer *ren){
  int i,j = 0;
  //std::cout << STAGE_WIDTH/BLOCK_WIDTH << " "  << STAGE_HEIGHT/BLOCK_HEIGHT << std::endl; 
  for(i=0;i<STAGE_WIDTH;i=i+BLOCK_WIDTH){
    for(j=0;j<STAGE_HEIGHT;j=j+BLOCK_HEIGHT){
      if(grid[i][j]){
        std::cout << i << " "  << j << " Is TRUE : " << grid[i][j] << std::endl; 
        std::cout << "grid_color = " << grid_color[i][j] << std::endl;
        std::cout << "grid_block = " << &grid_block[i][j] << std::endl;
        SDL_RenderCopy(ren,grid_color[i][j],NULL,&grid_block[i][j]);
      }
    }
  }
  //std::cout << "render stage" <<  std::endl;
}

void Stage::move_stagecolor_down(){
  std::cout << "move stage color down" << std::endl;
}

bool Stage::check_row(int row){
  std::cout << "check row()" << std::endl;
  return true;
}

void Stage::update_grid_status(int x, int y){
  std::cout << "update grid status " << std::endl;
  std::cout << x << y << std::endl;
  grid[x][y] = true;
}

void Stage::copy_block_color(Block* block){
  std::cout << "copy block color" << std::endl;
  int x = block -> get_block_x();
  int y = block -> get_block_y();
  if(grid[x][y]){
    grid_color[x][y] = block->get_block_texture();
    grid_block[x][y] = block->get_block_Rect();
  }
}

