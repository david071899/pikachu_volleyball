#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "image.h"
#include "console_draw3.h"
#include "kb_input2.h"
#include "header.h"


// pikachu width 64px height 64px
// ball width 30px height 18px

int main()
{
    int score = 0;
    Image *stick[1];
    Image *ground_line[1];
    Image *ground_edge[1];
    Image *scores[11];

    stick[0] = read_image("./image/stick/stick.pixel", "./image/stick/stick.color");
    ground_line[0] = read_image("./image/background/ground_line.pixel", "./image/background/ground_line.color");
    ground_edge[0] = read_image("./image/background/ground_edge.pixel", "./image/background/ground_edge.color");

    for (int i = 0; i < 10; ++i) {
        char pixel_path[100] = "./image/score/score_";
        char color_path[100] = "./image/score/score_";
        char order[9];

        itoa(i, order);
        strcat(pixel_path, order);
        strcat(pixel_path, ".pixel");

        printf("%s\n", pixel_path);

        strcat(color_path, order);
        strcat(color_path, ".color");

        scores[i] = read_image(pixel_path, color_path);
    }

    Pikachu p1;
    p1.x = P1_START_POS_X;
    p1.y = P1_START_POS_Y;
    p1.score = 0;
    p1.vector_y = 0;
    p1.jump_state = 0;
    p1.walk_iter = 0;
    p1.flap_iter = 0;
    p1.flap_left_state = 0;
    p1.flap_right_state = 0;
    p1.smash_state = 0;
    p1.win_state = 0;
    p1.walk[0] = read_image("./image/p1_walk/p1_walk1.pixel", "./image/p1_walk/p1_walk1.color");
    p1.walk[1] = read_image("./image/p1_walk/p1_walk2.pixel", "./image/p1_walk/p1_walk2.color");
    p1.walk[2] = read_image("./image/p1_walk/p1_walk3.pixel", "./image/p1_walk/p1_walk3.color");
    p1.walk[3] = read_image("./image/p1_walk/p1_walk4.pixel", "./image/p1_walk/p1_walk4.color");
    p1.walk[4] = read_image("./image/p1_walk/p1_walk5.pixel", "./image/p1_walk/p1_walk5.color");
    p1.flap_right[0] = read_image("./image/flapping/flap_right1.pixel", "./image/flapping/flap_right1.color");
    p1.flap_right[1] = read_image("./image/flapping/flap_right2.pixel", "./image/flapping/flap_right2.color");
    p1.flap_right[2] = read_image("./image/flapping/flap_right3.pixel", "./image/flapping/flap_right3.color");
    p1.flap_left[0] = read_image("./image/flapping/flap_left1.pixel", "./image/flapping/flap_left1.color");
    p1.flap_left[1] = read_image("./image/flapping/flap_left2.pixel", "./image/flapping/flap_left2.color");
    p1.flap_left[2] = read_image("./image/flapping/flap_left3.pixel", "./image/flapping/flap_left3.color");
    show_image(p1.walk[0], p1.x - 30, p1.y - 30);

    Pikachu p2;
    p2.x = P2_START_POS_X;
    p2.y = P2_START_POS_Y;
    p2.score = 0;
    p2.vector_y = 0;
    p2.jump_state = 0;
    p2.walk_iter = 0;
    p2.flap_iter = 0;
    p2.flap_left_state = 0;
    p2.flap_right_state = 0;
    p2.smash_state = 0;
    p2.win_state = 0;
    p2.walk[0] = read_image("./image/p2_walk/p2_walk1.pixel", "./image/p2_walk/p2_walk1.color");
    p2.walk[1] = read_image("./image/p2_walk/p2_walk2.pixel", "./image/p2_walk/p2_walk2.color");
    p2.walk[2] = read_image("./image/p2_walk/p2_walk3.pixel", "./image/p2_walk/p2_walk3.color");
    p2.walk[3] = read_image("./image/p2_walk/p2_walk4.pixel", "./image/p2_walk/p2_walk4.color");
    p2.walk[4] = read_image("./image/p2_walk/p2_walk5.pixel", "./image/p2_walk/p2_walk5.color");
    p2.flap_right[0] = read_image("./image/flapping/flap_right1.pixel", "./image/flapping/flap_right1.color");
    p2.flap_right[1] = read_image("./image/flapping/flap_right2.pixel", "./image/flapping/flap_right2.color");
    p2.flap_right[2] = read_image("./image/flapping/flap_right3.pixel", "./image/flapping/flap_right3.color");
    p2.flap_left[0] = read_image("./image/flapping/flap_left1.pixel", "./image/flapping/flap_left1.color");
    p2.flap_left[1] = read_image("./image/flapping/flap_left2.pixel", "./image/flapping/flap_left2.color");
    p2.flap_left[2] = read_image("./image/flapping/flap_left3.pixel", "./image/flapping/flap_left3.color");
    show_image(p2.walk[0], p2.x - 30, p2.y - 30);

    Ball ball;
    ball.x = BALL_INITIAL_POS_X;
    ball.y = BALL_INITIAL_POS_Y;
    ball.vector_x = BALL_INITIAL_SPEED_X;
    ball.vector_y = BALL_INITIAL_SPEED_Y;
    ball.img[0] = read_image("./image/ball/ball1.pixel", "./image/ball/ball1.color");
    show_image(ball.img[0], ball.x - 20, ball.y - 20);

	/* keyboard initial */
    initializeKeyInput();

    while (score < 16) {
        clearScreen();
        // ball position
        ball.vector_y += G;
        ball.y += ball.vector_y;
        ball.x = ball.x + ball.vector_x;
        if (ball.y + BALL_RADIUS >= HEIGHT) {
            //hit the roof
            ball.vector_y = -BALL_REBOUND_SPEED_Y;
            //++score;
        } else if (ball.y - BALL_RADIUS <= 0) {
            // hit the ground
            ball.vector_y = 1;
        }
        if (ball.x + BALL_RADIUS >= WIDTH) {
            // hit the right wall
            ball.vector_x = -BALL_REBOUND_SPEED_X;
        } else if (ball.x - BALL_RADIUS <= 0) {
            // hit the left wall
            ball.vector_x = BALL_REBOUND_SPEED_X;
        }
        // pikachu hit ball
        // pikachu 2
        double distance_of_p2 = sqrt(pow((ball.x + ball.vector_x - p2.x), 2) + pow((ball.y + ball.vector_y - p2.y - p2.vector_y), 2));
        double x_between_p2_and_ball = p2.x - ball.x;
        if (distance_of_p2 < 40) {
            if (x_between_p2_and_ball > 0) {
                if (p2.smash_state) {
                    ball.vector_x = -(abs(ball.vector_x) + abs(x_between_p2_and_ball)*SMASH_PARAM);
                } else {
                    ball.vector_x = -(abs(ball.vector_x) + abs(x_between_p2_and_ball)*NORMAL_REBOUND_PARAM);
                }
            } else {
                if (p2.smash_state) {
                    ball.vector_x = abs(ball.vector_x) + abs(x_between_p2_and_ball)*SMASH_PARAM;
                } else {
                    ball.vector_x = abs(ball.vector_x) + abs(x_between_p2_and_ball)*NORMAL_REBOUND_PARAM;
                }
            }
            ball.vector_y = -ball.vector_y;
        }
        // pikachu 1
        double distance_of_p1 = sqrt(pow((ball.x + ball.vector_x - p1.x), 2) + pow((ball.y + ball.vector_y - p1.y - p1.vector_y), 2));
        double x_between_p1_and_ball = p1.x - ball.x;
        if (distance_of_p1 < 40) {
            if (x_between_p1_and_ball > 0) {
                ball.vector_x = -(abs(ball.vector_x) + abs(x_between_p1_and_ball)*NORMAL_REBOUND_PARAM);
            } else {
                ball.vector_x = abs(ball.vector_x) + abs(x_between_p1_and_ball)*NORMAL_REBOUND_PARAM;
            }
            ball.vector_y = -ball.vector_y;
        }
        // ball hit stick
        double x_beteen_ball_and_stick = abs(ball.x + ball.vector_x - STICK_POS_X);
        double y_beteen_ball_and_stick = abs(ball.y + ball.vector_y - STICK_POS_Y);
        if (x_beteen_ball_and_stick <= BALL_RADIUS && ball.y + BALL_RADIUS > STICK_POS_Y) {
            // hit left or right
            ball.vector_x = -ball.vector_x;
        } else if (ball.x < (STICK_POS_X + 10) && ball.x > STICK_POS_X && y_beteen_ball_and_stick <= BALL_RADIUS) {
            // hit top
            ball.vector_y = -ball.vector_y;
        }
        // pikachu jumping
        // pikachu 2
        if (p2.jump_state == JUMP) {
            p2.vector_y += G;
            p2.y += p2.vector_y;
        }
        if (p2.y + P_RADIUS >= HEIGHT) {
            p2.vector_y = 0;
            p2.jump_state = STAY;
            p2.smash_state = 0;
        }
        // pikachu 1
        if (p1.jump_state == JUMP) {
            p1.vector_y += G;
            p1.y += p1.vector_y;
        }

        if (p1.y + P_RADIUS >= HEIGHT) {
            p1.vector_y = 0;
            p1.jump_state = STAY;
        }

        // score judge
        if (ball.y + BALL_RADIUS >= HEIGHT) {
            if (ball.x < STICK_POS_X - 10) {
                p2.score += 1;
                p2.win_state = 1;

                p1.win_state = 0;
            } else if (ball.x > STICK_POS_X + 10) {
                p1.score += 1;
                p1.win_state = 1;

                p2.win_state = 0;
            }
            initial_round(&ball, &p1, &p2);
        }

        //keyboard input
        // pikachu 2
        if (p2.flap_right_state == 0 && p2.flap_left_state == 0) {
            // can't do anything when flapping
            if (KEY_DOWN(VK_LEFT)) {
                if (p2.x - P_RADIUS >= STICK_POS_X) {
                    p2.x -= LEFT_MOVE_STEP;
                }
            }
            if (KEY_DOWN(VK_RIGHT)) {
                if (p2.x + P_RADIUS <= WIDTH) {
                    p2.x += RIGHT_MOVE_STEP;
                }
            }
            if (KEY_DOWN(VK_LEFT) && KEY_DOWN(VK_RETURN) && p2.jump_state == STAY) {
                p2.flap_left_state = 1;
            }
            if (KEY_DOWN(VK_RIGHT) && KEY_DOWN(VK_RETURN) && p2.jump_state == STAY) {
                p2.flap_right_state = 1;
            }
            if (KEY_DOWN(VK_UP) && p2.jump_state == STAY) {
                p2.jump_state = JUMP;
                p2.vector_y = JUMP_INITIAL_SPEED;
            }
            if (KEY_DOWN(VK_RETURN) && p2.jump_state == JUMP) {
                p2.smash_state = 1;
            }
        }

        // pikachu 1
        if (p1.flap_right_state == 0 && p1.flap_left_state == 0) {
            // can't do anything when flapping
            if (KEY_DOWN(VK_A)) {
                if (p1.x - P_RADIUS >= 0) {
                    p1.x -= LEFT_MOVE_STEP;
                }
            }
            if (KEY_DOWN(VK_D)) {
                if (p1.x + P_RADIUS <= STICK_POS_X) {
                    p1.x += RIGHT_MOVE_STEP;
                }
            }
            if (KEY_DOWN(VK_A) && KEY_DOWN(VK_SPACE) && p1.jump_state == STAY) {
                p1.flap_left_state = 1;
            }
            if (KEY_DOWN(VK_D) && KEY_DOWN(VK_SPACE) && p1.jump_state == STAY) {
                p1.flap_right_state = 1;
            }
            if (KEY_DOWN(VK_W) && p1.jump_state == STAY) {
                p1.jump_state = JUMP;
                p1.vector_y = JUMP_INITIAL_SPEED;
            }
        }
        show_image(scores[p1.score], P1_SCORE_X, P1_SCORE_Y);
        show_image(scores[p2.score], P2_SCORE_X, P1_SCORE_Y);
        show_image(ground_edge[0], GROUND_EDGE_X, GROUND_EDGE_Y);
        show_image(ground_line[0], GROUND_LINE_X, GROUND_LINE_Y);
        show_image(stick[0], STICK_POS_X, STICK_POS_Y);
        // show p1
        if (p1.flap_right_state) {
            int index = p1.flap_iter / 10;
            p1.flap_iter += 0.6;
            if (p1.flap_iter >= 30) {
                p1.flap_iter = 0;
                p1.flap_right_state = 0;
            }
            if (p1.x + P_RADIUS + RIGHT_MOVE_STEP <= STICK_POS_X) {
                p1.x += RIGHT_MOVE_STEP;
            }
            show_image(p1.flap_right[index], p1.x - P_RADIUS, p1.y - P_RADIUS);
        } else if (p1.flap_left_state) {
            int index = p1.flap_iter / 10;
            p1.flap_iter += 0.6;
            if (p1.flap_iter >= 30) {
                p1.flap_iter = 0;
                p1.flap_left_state = 0;
            }
            if (p1.x - P_RADIUS - LEFT_MOVE_STEP >= 0) {
                p1.x -= LEFT_MOVE_STEP;
            }
            show_image(p1.flap_left[index], p1.x - P_RADIUS, p1.y - P_RADIUS);
        } else {
            int index = p1.walk_iter / 10;
            p1.walk_iter += 1.2;
            if (p1.walk_iter >= 50) {
                p1.walk_iter = 0;
            }
            show_image(p1.walk[index], p1.x - P_RADIUS, p1.y - P_RADIUS);
        }
        // show p2
        if (p2.flap_right_state) {
            int index = p2.flap_iter / 10;
            p2.flap_iter += 0.6;
            if (p2.flap_iter >= 30) {
                p2.flap_iter = 0;
                p2.flap_right_state = 0;
            }
            if (p2.x + P_RADIUS + RIGHT_MOVE_STEP <= WIDTH) {
                p2.x += RIGHT_MOVE_STEP;
            }
            show_image(p2.flap_right[index], p2.x - P_RADIUS, p2.y - P_RADIUS);
        } else if (p2.flap_left_state) {
            int index = p2.flap_iter / 10;
            p2.flap_iter += 0.6;
            if (p2.flap_iter >= 30) {
                p2.flap_iter = 0;
                p2.flap_left_state = 0;
            }
            if (p2.x - P_RADIUS - LEFT_MOVE_STEP >= STICK_POS_X) {
                p2.x -= LEFT_MOVE_STEP;
            }
            show_image(p2.flap_left[index], p2.x - P_RADIUS, p2.y - P_RADIUS);
        } else {
            int index = p2.walk_iter / 10;
            p2.walk_iter += 1.2;
            if (p2.walk_iter >= 50) {
                p2.walk_iter = 0;
            }
            show_image(p2.walk[index], p2.x - P_RADIUS, p2.y - P_RADIUS);
        }
        show_image(ball.img[0], ball.x - BALL_RADIUS, ball.y - BALL_RADIUS);
        drawCmdWindow();
    }

    return 0;
}
