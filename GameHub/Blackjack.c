#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include "utils.h"


int main() {

// Starting Menu
    while(true){
    srand(time(0));
    int gamechoose;

    printf("==========GAME HUB==========EXIT(0)\n\n");
    printf("--Avaliable Games--\n");
    printf("1) Rock-Paper-Scissors\n");
    printf("2) Blackjack\n");
    

    do{
        printf("Choose a Game:");
       scanf("%d", &gamechoose);

       if(gamechoose == 0){
        printf("Exiting GameHub...");
        wait(2000);
        clear_screen();
        return 0;
       }
    
       if(gamechoose < 1 || gamechoose > 2){
        printf("Wrong input! Use 1 or 2\n");
        wait(1000);
} }while(gamechoose < 1 || gamechoose > 2);
clear_screen();
    
//-------------Rock-Paper-Scissors--------------------------

    if(gamechoose == 1) {
        gameexitrps = false;

        while(gameexitrps == false){
        char user_move;
        char *user_display;
        int ai_move = rand() % 3;
        char *ai_display[] = {"Rock", "Paper", "Scissors"};
        char *ai_displayBEFORE[] = {"Rock...", "Paper...", "Scissors...", "SHOOT!!!"};
        


        printf("==========ROCK-PAPER-SCISSORS==========EXIT(e)\n\n");
        printf("Rock(r) - Paper(p) - Scissors(s)\n");
        do{
        printf("Choose your Move:");
        scanf(" %c", &user_move);
        if(user_move == 'e'|| user_move == 'E'){
            break;
        }
        if (user_move != 'r' && user_move != 'p' && user_move != 's') {
        printf("Wrong input! Use r, p, s or e\n");
        wait(100);
    }
    } while(user_move != 'r' && user_move != 'p' && user_move != 's');
        
        if(user_move == 'e'|| user_move == 'E') {
            printf("Exiting Game...");
            wait(2000);
            clear_screen();
            gameexitrps = true;
            break;
        }

        determine_move(user_move, &user_display);
        clear_screen();

        printf("YOU: %s\n", user_display);

        for(int i = 0; i <= 3; i++){
        printf("\rAI Player: %s ",ai_displayBEFORE[i]); // Refresh same line for animation effect
        fflush(stdout); // Clear output buffer so line can update immediately
        wait(1000);
        printf("\r                                \r"); // Clear the line after animation
        }
        
        printf("\rAI Player: %s\n\n",ai_display[ai_move]);
        wait(1000);

        rps_winner(user_move, ai_move);
        printf("%s", rps_status);
        wait(2000);
        printf("\n----PREPARING NEXT GAME----\n");
        wait(2000);
        clear_screen();


        
    } 
}
//---------------Blackjack---------------------------------
    if(gamechoose == 2) {

    while(gameexitbj == false) {
    gameover = false; // This is here because "CheckWinner" functions sets gameover to true on every condition.
    int startinghand_d = getcard();
    int startinghand1_u = getcard();
    int startinghand2_u = getcard();
    int choice;
    int dealertotal = startinghand_d;
    int usertotal = startinghand1_u + startinghand2_u;


    
    clear_screen();
    printf("==========BLACKJACK========== | EXIT(e)\n\n");
    printf("Dealer's Hand: [Hidden] - %d | TOTAL: %d\n\n", startinghand_d, dealertotal);
    printf("Your Hand: %d - %d | TOTAL: %d\n", startinghand1_u, startinghand2_u, usertotal);
    do {choice = ask_user(choice);
    }
    while(choice < 0 || choice > 2 );

    

    while(gameover == false) {

        if(choice == 1) {
            while(dealertotal < DEALER_LIMIT){
                int tempdrew = dealertotal;
                dealertotal += getcard();
                printf("\nDealer Drew %d | TOTAl: %d\n", dealertotal - tempdrew , dealertotal);
                wait(1500);
                   CheckWinner(usertotal, dealertotal);
                    if(gameover == true) {
                    break;
                }
                } 
            }

        if(choice == 0) {
           while(choice == 0 && usertotal < MAX_LIMIT){
            int tempdrew = usertotal;
                usertotal += getcard();
                printf("\nYou Drew %d | TOTAL: %d\n", usertotal - tempdrew, usertotal);
                CheckWinner(usertotal, dealertotal);
                if(gameover == true) {
                    break;
                }
                do {choice = ask_user(choice);
                }
                while(choice < 0 || choice > 2 );
           }
            
        }
        if(choice == 2) {
            gameexitbj = true;
            printf("Exiting Game...\n");
            wait(2000);
            clear_screen();
            break;
            

        }
    }
}

}


    
}

//----------------------------------------------------------

}

