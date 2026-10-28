#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//jokenpo

int main(){
    srand(time(NULL)); 

    while(1) {
        int jdp;
        printf("\nChoose 1 for Rock, 2 for Paper, 3 for Scissors or 0 to quit: ");
        int lido = scanf("%d", &jdp);
        if (lido == EOF) {
            break;
        }
        if (lido != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Select a valid number!\n");
            continue;
        }

       
        if (jdp == 0) {
            printf("Leaving the game...\n");
            break; 
        }

        
        if (jdp < 1 || jdp > 3) {
            printf("Select a valid number!\n");
            continue;
        }

        int jdc = (rand() % 3)+1;

        if (jdp == jdc){
            printf("Draw!\n");
        }
        else if (jdp == 1 && jdc == 3){
            printf("Rock beats scissors, so you WIN!\n");
        }
        else if(jdp == 2 && jdc == 1){
            printf("Paper beats rock, so you WIN!\n");
        }
        else if(jdp == 3 && jdc == 2){
            printf("Scissors beats paper, so you WIN!\n");
        }
        else if (jdp == 3 && jdc == 1){
            printf("Rock beats scissors, so you LOSE!\n");
        }
        else if(jdp == 1 && jdc == 2){
            printf("Paper beats rock, so you LOSE!\n");
        }
        else if(jdp == 2 && jdc == 3){
            printf("Scissors beats paper, so you LOSE!\n");
        }
         printf("\n--------------------------------");
       
    

   
     }
 return 0;
}


/* 1 > 3
   2 > 1
   3 > 2

*/
