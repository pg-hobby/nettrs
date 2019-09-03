#include "Game.hpp"
#include "GameConfig.hpp"

static const char *WIN_TITLE = "T E T R I S";

Game *game = nullptr;

int main(int argc, const char *argv[]) {

  Uint32 frameStart;
  int frameTime;

  game = new Game();
  game -> init(WIN_TITLE,SDL_WINDOWPOS_CENTERED,
               SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, false);
  while (game -> runnig()) {
    frameStart = SDL_GetTicks();
    //handle any user inpput
    game -> handleEvents();
    //update all object eg postioning etc
    game -> update();
    //render change to display
    game -> render();

    frameTime = SDL_GetTicks() - frameStart;

    if (FRAME_DELAY > frameTime)
      SDL_Delay(FRAME_DELAY - frameTime);
  }
  game -> clean();
  return 0;
}
