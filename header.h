#include "./tool_function/image.h"
#ifndef HEADER_
#define HEADER_

typedef struct _pikachu {
    int x;
    int y;
    int score;
    float flap_iter;
    float walk_iter;
    int jump_state;
    int smash_state;
    int flap_left_state;
    int flap_right_state;
    int win_state;
    double vector_y;
    Image *walk[5];
    Image *flap_left[3];
    Image *flap_right[3];
} Pikachu;

typedef struct _ball {
    int x;
    int y;
    double vector_x;
    double vector_y;
    Image *img[3];
} Ball;

// frame width & height
#define WIDTH 600
#define HEIGHT 185
// ball radius
#define BALL_RADIUS 20
// pikachu initial position
#define P1_START_POS_X 35
#define P1_START_POS_Y 160
#define P2_START_POS_X 570
#define P2_START_POS_Y 160
// pikachu radius
#define P_RADIUS 30
// ball initial position
#define BALL_INITIAL_POS_X 50
#define BALL_INITIAL_POS_Y 25
// ball initial speed
#define BALL_INITIAL_SPEED_X 0
#define BALL_INITIAL_SPEED_Y 1
// ball rebound speed
#define BALL_REBOUND_SPEED_X 1
#define BALL_REBOUND_SPEED_Y 3
// acceleration
#define G 0.1
// pikachu jump state
#define STAY 0
#define JUMP 1
// pikachu jump a
#define JUMP_INITIAL_SPEED -3.5
// stick position
#define STICK_POS_X 300
#define STICK_POS_Y 90
// ball params
#define NORMAL_REBOUND_PARAM 0.07
#define SMASH_PARAM 1
// pikachu moving speed
#define LEFT_MOVE_STEP 2.25
#define RIGHT_MOVE_STEP 3
// p1 score position
#define P1_SCORE_X 30
#define P1_SCORE_Y 10
// p2 score position
#define P2_SCORE_X 550
#define P2_SCORE_Y 10
//ground edge position
#define GROUND_EDGE_X 0
#define GROUND_EDGE_Y 165
//ground line position
#define GROUND_LINE_X 0
#define GROUND_LINE_Y 180


#endif
