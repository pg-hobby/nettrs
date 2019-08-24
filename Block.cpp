#include "Block.hpp"
#include "TextureManager.hpp"

#include <iostream>

Block::Block(SDL_Renderer *ren){
  std::cout << "Block()" << std::endl;
  block_texture = TextureManager::LoadTexture(TEXTURE_PATH,ren);
  std::cout << "Texture loaded" << std::endl;
  block.h = BLOCK_HEIGHT;   
  block.w = BLOCK_WIDTH;   
  block.x = STAGE_WIDTH/2-BLOCK_WIDTH;   
  block.y = 0;   
}

Block::~Block(){
}

void Block::move_block_right(){
  //std::cout << "move to right" << std::endl;
  block.x = block.x + BLOCK_WIDTH;
  if(block.x >= STAGE_WIDTH) block.x = STAGE_WIDTH - BLOCK_WIDTH;

}
void Block::move_block_left(){
  //std::cout << "move to left" << std::endl;
  block.x = block.x - BLOCK_WIDTH;
  if(block.x < 0) block.x = 0;
}
void Block::move_block_downfast(){
  //std::cout << "move to down" << std::endl;
  block.y = block.y + BLOCK_HEIGHT;
  if(block.y >= STAGE_HEIGHT - BLOCK_HEIGHT){
    block.y = STAGE_HEIGHT - BLOCK_HEIGHT;
    isDead  = true; 
  }
}


void Block::rotate_block(){
  std::cout << "rotate" << std::endl;
}

int Block::get_block_x(){
  return block.x;
}

int Block::get_block_y(){
  return block.y;
}
void Block::render_block(SDL_Renderer *ren){
  //std::cout << "render block" << std::endl;
  SDL_RenderCopy(ren,block_texture,NULL,&block);
}



