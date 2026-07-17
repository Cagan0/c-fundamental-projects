#include <windows.h>
#include <stdio.h>
#include "utils.h"

bool gameover = false;
bool gameexitrps = false;
bool gameexitbj = false;
char *rps_status = "";

void clear_screen() {
    system("cls");
}

void wait(int time) {
    Sleep(time);
}

int ask_user(int choice){
    char input;
    printf("Do You Want To HIT(h) or STAY(s)?\n");
    printf("Choose: ");
    scanf(" %c", &input);  // Boşluk karakteri önceki newline'ı temizler
    
    if (input == 'h' || input == 'H') {
        choice = 0;
    } else if (input == 's' || input == 'S') {
        choice = 1;
    } else if (input == 'e' || input == 'E') {
        choice = 2;
    } else {
        printf("!!! You Must Type (h) - (s) - (e for exit) !!!\n");
        wait(2500);
        choice = -1;  // Geçersiz değer
    }
    return choice;
}

int getcard() {
    int card = (rand() % 13) + 1;
    if (card > 10) {
        card = 10;
    }
    return card;
}

void CheckWinner(int usertotal, int dealertotal) {
    if (dealertotal == MAX_LIMIT) {
        printf("You LOST!!!\n\n");
        printf("----PREPARING NEXT GAME----");
        gameover = true;
        wait(4000);
    }else if (usertotal == MAX_LIMIT) {
        printf("You WON!!!\n\n");
        printf("----PREPARING NEXT GAME----");
        gameover = true;
        wait(4000);
    }else if(usertotal > MAX_LIMIT) {
        printf("You LOST!!!\n\n");
        printf("----PREPARING NEXT GAME----");
        gameover = true;
        wait(4000);
    }else if(dealertotal > MAX_LIMIT) {
        printf("You WON!!!\n\n");
        printf("----PREPARING NEXT GAME----");
        gameover = true;
        wait(4000);
    } else if (dealertotal >= DEALER_LIMIT && dealertotal < MAX_LIMIT) {
        if(usertotal > dealertotal){
            printf("You WON!!!\n\n");
            printf("----PREPARING NEXT GAME----");
            gameover = true;
            wait(4000);
        } else if (usertotal < dealertotal) {
            printf("You LOST!!!\n\n");
            printf("----PREPARING NEXT GAME----");
            gameover = true;
            wait(4000);
        } else if (usertotal == dealertotal) {
            printf("TIE!!!\n\n");
            printf("----PREPARING NEXT GAME----");
            gameover = true;
            wait(4000);
        }
    }
}

void determine_move(char user_move, char **user_display){
    if(user_move == 'r' || user_move == 'R'){
        *user_display = "Rock";
    }

    if(user_move == 'p' || user_move == 'P'){
        *user_display = "Paper";
    }

    if(user_move == 's' || user_move == 'S'){
        *user_display = "Scissors";
    }
}

void rps_winner(char user_move, int ai_move) {
    if(user_move == 'r' && ai_move == AI_ROCK){
        rps_status = "DRAW!!\n";
    } else if(user_move == 'r' && ai_move == AI_PAPER){
        rps_status = "YOU LOSE!!\n";
    } else if(user_move == 'r' && ai_move == AI_SCISSORS){
        rps_status = "YOU WIN!!\n";
    } else if(user_move == 'p' && ai_move == AI_ROCK){
        rps_status = "YOU WIN!!\n";
    } else if(user_move == 'p' && ai_move == AI_PAPER){
        rps_status = "DRAW!!\n";
    } else if(user_move == 'p' && ai_move == AI_SCISSORS){
        rps_status = "YOU LOSE!!\n";
    } else if(user_move == 's' && ai_move == AI_ROCK){
        rps_status = "YOU LOSE!!\n";
    } else if(user_move == 's' && ai_move == AI_PAPER){
        rps_status = "YOU WIN!!\n";
    } else if(user_move == 's' && ai_move == AI_SCISSORS){
        rps_status = "DRAW!!\n";
    }
}