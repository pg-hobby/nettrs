#include "Stage.hpp"
#include "Block.hpp"
#include "TextureManager.hpp"

#include <iostream> 

Stage::Stage(){
  std::cout << "Stage () " << std::endl;
}

Stage::~Stage(){
  std::cout << "~Stage() " << std::endl;
}

void Stage::render_stage(){
  std::cout << "render stage" <<  std::endl;
}

void Stage::move_stagecolor_down(){
  std::cout << "move stage color down" << std::endl;
}

bool Stage::check_row(int row){
  std::cout << "check row()" << std::endl;
  return true;
}

void Stage::copy_block_color(){
  std::cout << "copy block color" << std::endl; 
}

