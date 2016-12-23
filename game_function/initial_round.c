#include "initial_round.h"

void initial_round (Ball *ball, Pikachu *p1, Pikachu *p2) {

    p1->x = P1_START_POS_X;
    p1->y = P1_START_POS_Y;
    p1->x = P1_START_POS_X;
    p1->y = P1_START_POS_Y;
    p1->vector_y = 0;
    p1->jump_state = 0;
    p1->walk_iter = 0;
    p1->flap_iter = 0;
    p1->flap_left_state = 0;
    p1->flap_right_state = 0;
    p1->smash_state = 0;

    p2->x = P2_START_POS_X;
    p2->y = P2_START_POS_Y;
    p2->vector_y = 0;
    p2->jump_state = 0;
    p2->walk_iter = 0;
    p2->flap_iter = 0;
    p2->flap_left_state = 0;
    p2->flap_right_state = 0;
    p2->smash_state = 0;

    if (p1->win_state) {
        ball->x = BALL_INITIAL_POS_X;
        ball->y = BALL_INITIAL_POS_Y;
        ball->vector_x = BALL_INITIAL_SPEED_X;
        ball->vector_y = BALL_INITIAL_SPEED_Y;
    } else {
        ball->x = BALL_INITIAL_POS_X + 500;
        ball->y = BALL_INITIAL_POS_Y;
        ball->vector_x = BALL_INITIAL_SPEED_X;
        ball->vector_y = BALL_INITIAL_SPEED_Y;
    }

}
