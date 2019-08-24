#include "Block.hpp"
#include "TextureManager.hpp"

#include <iostream>

Block::Block(){
  std::cout << "Block()" << std::endl;
}

Block::~Block(){
  std::cout << "~Block()" << std::endl;
}

void Block::move_block_right(){

  std::cout << "move to right" << std::endl;

}
void Block::move_block_left(){
    
  std::cout << "move to left" << std::endl;
}
void Block::move_block_downfast(){
  
  std::cout << "move to down" << std::endl;

}
void Block::rotate_block(){

  std::cout << "rotate" << std::endl;
}

void Block::render_block(){
  std::cout << "render block" << std::endl;
}


