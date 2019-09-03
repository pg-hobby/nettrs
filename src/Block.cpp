#include "Block.hpp"
#include "Stage.hpp"
#include "TextureManager.hpp"

Block::Block(SDL_Renderer *ren){
  block_texture = TextureManager::LoadTexture(TEXTURE_PATH,ren);
  block.h = BLOCK_HEIGHT;   
  block.w = BLOCK_WIDTH;   
  block.x = STAGE_WIDTH/2-BLOCK_WIDTH;   
  block.y = 0;   
}

Block::~Block(){
}

void Block::move_block_right(){
  block.x = block.x + BLOCK_WIDTH;
  if(block.x >= STAGE_WIDTH) block.x = STAGE_WIDTH - BLOCK_WIDTH;

}
void Block::move_block_left(){
  block.x = block.x - BLOCK_WIDTH;
  if(block.x < 0) block.x = 0;
}
void Block::move_block_downfast(bool status){
  if(status){debug("is occupied");isDead=true; return;}
  block.y = block.y + BLOCK_HEIGHT;
  if(block.y >= STAGE_HEIGHT - BLOCK_HEIGHT){
    block.y = STAGE_HEIGHT - BLOCK_HEIGHT;
    isDead  = true; 
  }
}


void Block::rotate_block(){
  debug("rotate");
}

int Block::get_block_x(){
  return block.x;
}

int Block::get_block_y(){
  return block.y;
}
void Block::render_block(SDL_Renderer *ren){
  SDL_RenderCopy(ren,block_texture,NULL,&block);
}

