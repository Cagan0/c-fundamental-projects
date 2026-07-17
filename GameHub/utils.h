#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define DEALER_LIMIT 17
#define MAX_LIMIT 21
#define AI_ROCK 0
#define AI_PAPER 1
#define AI_SCISSORS 2

extern bool gameover;
extern bool gameexitrps;
extern bool gameexitbj;
extern char *rps_status;



//General utility fucntions for the project
void clear_screen();
void wait(int time);

//Blackjack specific utility functions
int ask_user(int choice);
int getcard();
void CheckWinner(int usertotal, int dealertotal);

//Rock-Paper-Scissors specific utility functions
void determine_move(char user_move, char **user_display);
void rps_winner(char user_move, int ai_move);

#endif