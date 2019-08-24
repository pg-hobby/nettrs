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
#define FRAME_DELAY 1000/FPS

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

#define TEXTURE_PATH "/home/haroon/work/net_tetris/Tetris_in_cpp/test.png"
