#include <stdio.h>
char selectl;
int selectn;

int main() {
    setbuf(stdout, NULL);
    char tabuleiro[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };
    int jogadas = 0;
    int ganhou = 0;

    while (jogadas < 9 && ganhou == 0) {
        printf(" _%c_|_%c_|_%c_ \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
        printf(" _%c_|_%c_|_%c_ \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
        printf("  %c | %c | %c  \n",  tabuleiro[6], tabuleiro[7], tabuleiro[8]);
       
      
		do {
            printf("\nPlease, select: O or X: ");
		    scanf(" %c", &selectl);

            if (selectl != 'X' && selectl != 'x' && selectl != 'O' && selectl != 'o') {
                printf("Wrong letter! Try again.\n");
            }
        } while (selectl != 'X' && selectl != 'x' && selectl != 'O' && selectl != 'o');
		
       
        int posicao_valida = 0;
        do {
		    printf("\nSelect 1, 2, 3, 4, 5, 6, 7, 8 or 9: ");
            scanf("%d", &selectn);
		
		    if (selectn >= 1 && selectn <= 9) {
                
                char atual = tabuleiro[selectn - 1];
                if (atual == 'X' || atual == 'x' || atual == 'O' || atual == 'o') {
                    printf("This position is already taken! Try another one.\n");
                } else {
                    tabuleiro[selectn - 1] = selectl;
                    jogadas++;
                    posicao_valida = 1; 
                }
            } else {
                printf("Invalid position! Select a number between 1 and 9.\n");
            }
        } while (posicao_valida == 0);
       
       
		if (tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2]) ganhou = 1;
        if (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5]) ganhou = 1;
        if (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8]) ganhou = 1;
        if (tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6]) ganhou = 1;
        if (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7]) ganhou = 1;
        if (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8]) ganhou = 1;
        if (tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8]) ganhou = 1;
        if (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6]) ganhou = 1;

        if (ganhou == 1) {
            printf("\n _%c_|_%c_|_%c_ \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
            printf(" _%c_|_%c_|_%c_ \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
            printf("  %c | %c | %c  \n",  tabuleiro[6], tabuleiro[7], tabuleiro[8]);
            printf("\nPARABENS! O jogador [%c] ganhou o jogo!\n\n", selectl);
        } else {
            printf("\n--- Next Round ---\n\n");
        }
    }

    if (jogadas == 9 && ganhou == 0) {
        printf("\nOpss! We have a draw.\n\n");
    }
    return 0;
}
