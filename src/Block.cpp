#include "Block.hpp"
#include "Stage.hpp"
#include "TextureManager.hpp"

/*
 * --------------------------------------------------------------
 * BLOCK:I  BLOCK:O  BLOCK:S  BLOCK:Z  BLOCK:J  BLOCK:L  BLOCK:T
 * --------------------------------------------------------------
 * □■□□ □□□□ □□□□ □□□□ □■□□ □■□□ □■□□
 * □●□□ □■■□ □●■□ ■■□□ □●□□ □●□□ ■●■□
 * □■□□ □■■□ ■■□□ □●■□ ■■□□ □■■□ □□□□
 * □■□□ □□□□ □□□□ □□□□ □□□□ □□□□ □□□□
 *
 * --------------------------------------------------------------
 * BLOCK:i  BLOCK:l
 * --------------------------------------------------------------
 * □■□□ □□□□
 * □●□□ □■□□
 * □■□□ □●■□
 * □□□□ □□□□
 */
static const mino blockinfo[] = {
/* NAME COLOR                     AXIS    LOCAL1  LOCAL2  LOCAL3   */
  {'I', TEXTURE_LIGHTBLUE_PATH,  {{1, 1}, {1, 0}, {1, 2}, {1, 3}}},
  {'O', TEXTURE_YELLOW_PATH,     {{1, 1}, {2, 1}, {1, 2}, {2, 2}}},
  {'S', TEXTURE_GREEN_PATH,      {{1, 1}, {2, 1}, {0, 2}, {1, 2}}},
  {'Z', TEXTURE_RED_PATH,        {{1, 2}, {0, 1}, {1, 1}, {2, 2}}},
  {'J', TEXTURE_BLUE_PATH,       {{1, 1}, {1, 0}, {0, 2}, {1, 2}}},
  {'L', TEXTURE_ORANGE_PATH,     {{1, 1}, {1, 0}, {1, 2}, {2, 2}}},
  {'T', TEXTURE_PURPLE_PATH,     {{1, 1}, {0, 1}, {1, 0}, {2, 1}}},
  {'i', TEXTURE_LIGHTGREEN_PATH, {{1, 1}, {1, 0}, {1, 2}, {1, 2}}},
  {'l', TEXTURE_PINK_PATH,       {{1, 2}, {1, 1}, {2, 2}, {2, 2}}},
};

Block::Block(Btype btype, SDL_Renderer *ren) {
  set_block(((STAGE_WIDTH / 2) - BLOCK_WIDTH), /* x */
              0,                               /* y */
              BLOCK_WIDTH,                     /* width */
              BLOCK_HEIGHT,                    /* height */
              btype,                           /* block type */
              ren);
}

Block::~Block() {
}

void Block::move_block_right(bool status) {
  if (status)
    return;
  for (int i = 0; i < BLOCK_COUNT; i++) {
    blocks[i].x = blocks[i].x + BLOCK_WIDTH;
    if (blocks[i].x >= STAGE_WIDTH)
      blocks[i].x = STAGE_WIDTH - BLOCK_WIDTH;
  }
}
void Block::move_block_left(bool status) {
  if (status)
    return;
  for (int i = 0; i < BLOCK_COUNT; i++) {
    blocks[i].x = blocks[i].x - BLOCK_WIDTH;
    if (blocks[i].x < 0)
      blocks[i].x = 0;
  }
}
void Block::move_block_downfast(bool status) {
  if (status) {
    debug("is occupied");
    isDead=true;
    return;
  }
  for (int i = 0; i < BLOCK_COUNT ; i++) {
    blocks[i].y = blocks[i].y + BLOCK_HEIGHT;
    if (blocks[i].y > (STAGE_HEIGHT - BLOCK_HEIGHT)) {
      blocks[i].y = STAGE_HEIGHT - BLOCK_HEIGHT;
      isDead  = true;
    }
  }
}

void Block::rotate_block(bool status) {
  if (status) {
    debug("is occupied");
    return;
  }
  if (blocktype == BLOCK_O) {
    return;
  }
  int x_axis = blocks[0].x;
  int y_axis = blocks[0].y;
  for (int i = 1; i < BLOCK_COUNT ; i++) {
    int x_vec = blocks[i].x - x_axis;
    int y_vec = blocks[i].y - y_axis;
    blocks[i].x = x_axis + y_vec;
    blocks[i].y = y_axis - x_vec;
  }
}

int Block::get_block_x() {
  return blocks[0].x;
}
int Block::get_block_y() {
  return blocks[0].y;
}
int Block::get_block_x(int i) {
  return blocks[i].x;
}
int Block::get_block_y(int i) {
  return blocks[i].y;
}

void Block::render_block(SDL_Renderer *ren){
  for (int i = 0; i < BLOCK_COUNT; i++)
    SDL_RenderCopy(ren, block_texture, NULL, &blocks[i]);
}

void Block::init_block(int x, int y, int w, int h){
  for (int i = 0; i < BLOCK_COUNT; i++) {
    blocks[i].x = x;
    blocks[i].y = y;
    blocks[i].w = w;
    blocks[i].h = h;
  }
}

void Block::set_block(int x, int y, int w, int h, Btype type, SDL_Renderer *ren){
  init_block(x, y, w, h);
  blocktype = type;
  block_texture = TextureManager::LoadTexture(blockinfo[type].path, ren);

  for(int i = 0; i < BLOCK_COUNT; i++) {
    blocks[i].x += blockinfo[type].p[i].x * blocks[i].w;
    blocks[i].y += blockinfo[type].p[i].y * blocks[i].h;
  }
}
