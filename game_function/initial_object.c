#include "initial_object.h"

void initial_object(Ball *ball,Pikachu *p1, Pikachu *p2) {

    p1->x = P1_START_POS_X;
    p1->y = P1_START_POS_Y;
    p1->score = 0;
    p1->vector_y = 0;
    p1->jump_state = 0;
    p1->walk_iter = 0;
    p1->flap_iter = 0;
    p1->flap_left_state = 0;
    p1->flap_right_state = 0;
    p1->smash_state = 0;
    p1->win_state = 0;
    // cause p1 & p2 declare in main so the path is base on main.c
    p1->walk[0] = read_image("./image/p1_walk/p1_walk1.pixel", "./image/p1_walk/p1_walk1.color");
    p1->walk[1] = read_image("./image/p1_walk/p1_walk2.pixel", "./image/p1_walk/p1_walk2.color");
    p1->walk[2] = read_image("./image/p1_walk/p1_walk3.pixel", "./image/p1_walk/p1_walk3.color");
    p1->walk[3] = read_image("./image/p1_walk/p1_walk4.pixel", "./image/p1_walk/p1_walk4.color");
    p1->walk[4] = read_image("./image/p1_walk/p1_walk5.pixel", "./image/p1_walk/p1_walk5.color");
    p1->flap_right[0] = read_image("./image/flapping/flap_right1.pixel", "./image/flapping/flap_right1.color");
    p1->flap_right[1] = read_image("./image/flapping/flap_right2.pixel", "./image/flapping/flap_right2.color");
    p1->flap_right[2] = read_image("./image/flapping/flap_right3.pixel", "./image/flapping/flap_right3.color");
    p1->flap_left[0] = read_image("./image/flapping/flap_left1.pixel", "./image/flapping/flap_left1.color");
    p1->flap_left[1] = read_image("./image/flapping/flap_left2.pixel", "./image/flapping/flap_left2.color");
    p1->flap_left[2] = read_image("./image/flapping/flap_left3.pixel", "./image/flapping/flap_left3.color");

    p2->x = P2_START_POS_X;
    p2->y = P2_START_POS_Y;
    p2->score = 0;
    p2->vector_y = 0;
    p2->jump_state = 0;
    p2->walk_iter = 0;
    p2->flap_iter = 0;
    p2->flap_left_state = 0;
    p2->flap_right_state = 0;
    p2->smash_state = 0;
    p2->win_state = 0;
    p2->walk[0] = read_image("./image/p2_walk/p2_walk1.pixel", "./image/p2_walk/p2_walk1.color");
    p2->walk[1] = read_image("./image/p2_walk/p2_walk2.pixel", "./image/p2_walk/p2_walk2.color");
    p2->walk[2] = read_image("./image/p2_walk/p2_walk3.pixel", "./image/p2_walk/p2_walk3.color");
    p2->walk[3] = read_image("./image/p2_walk/p2_walk4.pixel", "./image/p2_walk/p2_walk4.color");
    p2->walk[4] = read_image("./image/p2_walk/p2_walk5.pixel", "./image/p2_walk/p2_walk5.color");
    p2->flap_right[0] = read_image("./image/flapping/flap_right1.pixel", "./image/flapping/flap_right1.color");
    p2->flap_right[1] = read_image("./image/flapping/flap_right2.pixel", "./image/flapping/flap_right2.color");
    p2->flap_right[2] = read_image("./image/flapping/flap_right3.pixel", "./image/flapping/flap_right3.color");
    p2->flap_left[0] = read_image("./image/flapping/flap_left1.pixel", "./image/flapping/flap_left1.color");
    p2->flap_left[1] = read_image("./image/flapping/flap_left2.pixel", "./image/flapping/flap_left2.color");
    p2->flap_left[2] = read_image("./image/flapping/flap_left3.pixel", "./image/flapping/flap_left3.color");

    ball->x = BALL_INITIAL_POS_X;
    ball->y = BALL_INITIAL_POS_Y;
    ball->vector_x = BALL_INITIAL_SPEED_X;
    ball->vector_y = BALL_INITIAL_SPEED_Y;
    ball->img[0] = read_image("./image/ball/ball1.pixel", "./image/ball/ball1.color");

}
