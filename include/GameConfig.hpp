#pragma once

//window size configure
#define WIN_WIDTH STAGE_WIDTH
#define WIN_HEIGHT STAGE_HEIGHT

//stage configure
#define STAGE_HEIGHT  500
#define STAGE_WIDTH   500
#define STAGE_GRAVITY 50

// blocks configure
#define BLOCK_HEIGHT 50
#define BLOCK_WIDTH  50

//Game FPS
#define FPS 60
#define FRAME_DELAY (1000 / FPS)

//color configure
#define WHITE_INIT_CODE {255, 255, 255, 255}
#define BLACK_INIT_CODE {0,   0,   0,   255}
#define COLOR0_INIT_CODE {255, 0,   0,   255}
#define COLOR1_INIT_CODE {0,   255, 0,   255}
#define COLOR2_INIT_CODE {0,   0,   255, 255}
#define COLOR3_INIT_CODE {255, 255, 0,   255}
#define COLOR4_INIT_CODE {255, 0,   255, 255}
#define COLOR5_INIT_CODE {0,   255, 255, 255}
#define COLOR6_INIT_CODE {0,   128, 255, 255}

// texture path
#define TEXTURE_BROWN_PATH      "resources/block_brown.bmp"
#define TEXTURE_PINK_PATH       "resources/block_pink.bmp"
#define TEXTURE_RED_PATH        "resources/block_red.bmp"
#define TEXTURE_ORANGE_PATH     "resources/block_orange.bmp"
#define TEXTURE_YELLOW_PATH     "resources/block_yellow.bmp"
#define TEXTURE_LIGHTGREEN_PATH "resources/block_lightgreen.bmp"
#define TEXTURE_GREEN_PATH      "resources/block_green.bmp"
#define TEXTURE_LIGHTBLUE_PATH  "resources/block_lightblue.bmp"
#define TEXTURE_BLUE_PATH       "resources/block_blue.bmp"
#define TEXTURE_PURPLE_PATH     "resources/block_purple.bmp"
