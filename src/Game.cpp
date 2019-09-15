#include "Game.hpp"
#include "Block.hpp"
#include "Stage.hpp"

Block *block = nullptr;
Stage *stage = nullptr;
std::stack<Btype> blocktype;

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags = 0;
  Btype type = get_blocktype();
  if (fullscreen)
    flags = SDL_WINDOW_FULLSCREEN;

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    debug_game("Subsystem initalized");
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (window) {
      debug_game("Window Created ");
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      debug_game("Renderer Created ");
    }

    isRunning = true;
    stage = new Stage();
    block = new Block(type, renderer);
  }
  else {
    isRunning = false;
  }
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type){
    case SDL_QUIT: {
      isRunning = false;
      break;
    }
    case SDL_KEYDOWN: {
      switch (event.key.keysym.sym) {
        //move block to right
        case SDLK_RIGHT: {
          block -> move_block_right();
          break;
        }
        //move block to left
        case SDLK_LEFT: {
          block -> move_block_left();
          break;
        }
        //move block down fast
        case SDLK_DOWN: {
          bool status = true;
          for (int i = 0; i < BLOCK_COUNT && status; i++) {
            int x = block -> get_block_x(i);
            int y = block -> get_block_y(i);
            status = stage -> get_grid_status(x, y + BLOCK_HEIGHT);
          }
          block -> move_block_downfast(status);
          break;
        }
        // rotate block
        case SDLK_SPACE: {
          block -> rotate_block();
          break;
        }
        //do nothing
        default: {
          break;
        }
      }
    }
    default : {
      // do nothing
      break;
    }
  }
}

void Game::update(){
  Btype type = get_blocktype();
  //check if block is falling or stopped
  if (block -> Dead()) {
    //change grid color if occupied
    for (int i = 0; i < BLOCK_COUNT; i++) {
      stage -> update_grid_status(block -> get_block_x(i),
                                  block -> get_block_y(i));
      stage -> copy_block_color(block);
    }
    delete block; //destroy block instance
    //check if row is occupied
    int row = STAGE_HEIGHT;
    while (stage -> check_row(row)) {
       //move stage color to downwards
       stage -> move_stagecolor_down();
       row = row - BLOCK_HEIGHT;
     }
    // make new block to fall
    block = new Block(type, renderer);
  }
}

void Game::render() {
  SDL_RenderClear(renderer);
  //render copy block
  block -> render_block(renderer);
  //render copy stage
  stage -> render_stage(renderer);
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  debug_game("Game::clean()");
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  debug_game("Game Ended ....");
}

Btype Game::get_blocktype() {
  Btype btmp;
  if (!blocktype.size()) {
    Btype tmp[]{
      BLOCK_I,
      BLOCK_J,
      BLOCK_L,
      BLOCK_O,
      BLOCK_Z,
      BLOCK_S,
      BLOCK_T,
      BLOCK_SI,
      BLOCK_SL,
    };
    std::random_shuffle(tmp, tmp + BLOCK_MAX);
    for(int i = 0; i < BLOCK_MAX; i++)
      blocktype.push(tmp[i]);
  }
  btmp = blocktype.top();
  blocktype.pop();
  return btmp;
}
