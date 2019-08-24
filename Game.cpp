#include "Game.hpp"
#include "Block.hpp"
#include "Stage.hpp"

Block* block = nullptr;
Stage* stage = nullptr;

Game::Game(){}
Game::~Game(){}

void Game::init(const char* title,int xpos,int ypos, int width, int height, bool fullscreen){

  int flags = 0;
  if(fullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout << "Subsystem initalized" << std::endl;
    window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);

    if(window){
      std::cout << "Window Created " << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer){
      SDL_SetRenderDrawColor(renderer,255,255,255,255);
      std::cout << "Renderer Created " << std::endl;
    }

    isRunning = true;
    stage = new Stage();
    block = new Block(renderer);
  }
  else{
    isRunning = false;
  }

}

void Game::handleEvents(){
  //std::cout << "handle events" << std::endl;
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type){
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym){
        case SDLK_RIGHT:{
          block -> move_block_right();//move block to right
          break;
          }
        case SDLK_LEFT:{
          block -> move_block_left();//move block to left
          break;
          }
        case SDLK_DOWN:{
          int x = block -> get_block_x();
          int y = block -> get_block_y();
          bool status = stage->get_grid_status(x,y+BLOCK_HEIGHT);
          block -> move_block_downfast(status);// move block down fast
          break;
          }
        case SDLK_SPACE:{
          block -> rotate_block();// rotate block
          break;
          }
        default:{
          //do nothing
          break;
          }
      }
    default : 
      // do nothing
      break;
  } 
}

void Game::update(){
  //check if block is falling or stopped
  if(block -> Dead()){
    //change grid color if occupied
    stage -> update_grid_status(block->get_block_x(),block->get_block_y());
    stage -> copy_block_color(block);
    delete block; //destroy block instance 
    //check if row is occupied
    //int row; 
    // while(stage -> check_row(row = STAGE_HEIGHT)){ 
    //   //move stage color to downwards
    //   stage -> move_stagecolor_down();
    //   row = row - BLOCK_WIDTH;
    // } 
    // make new block to fall
    block = new Block(renderer);
  }
}

void Game::render(){
  //std::cout << "Game::render()" << std::endl;
  SDL_RenderClear(renderer);
  //render copy block
  block -> render_block(renderer);
  //render copy stage
  stage -> render_stage(renderer);
  SDL_RenderPresent(renderer);
}

void Game::clean(){
  std::cout << "Game::clean()" << std::endl;
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Ended ...." << std::endl;

}


