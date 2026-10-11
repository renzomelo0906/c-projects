#include <stdio.h>
#include <string.h>

struct contato {
    char nome[50];
    char telefone[20];
    char email[100];
}; 

int main() {	
    struct contato agenda[100];
    int total = 0;
    int selec;
    FILE *fptr;
    int c;

    fptr = fopen("contatos.txt", "r");
    if (fptr != NULL) {
        while (total < 100 && fscanf(fptr, " %49[^;\n];%19[^;\n];%99[^;\n]\n", agenda[total].nome, agenda[total].telefone, agenda[total].email) == 3) {
            total++;
        }
        fclose(fptr);
    }

    while(1){

printf("[1] Adicionar contato [2] Listar contatos [3] Sair:  ");
        int res = scanf("%d", &selec);
        
        if (res == EOF) {
            return 0;
        }
        if (res != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);

        if (selec == 3) {
            return 0; 
        } 
        
		else if (selec == 1) { 
            if (total >= 100) {
                printf("\nErro: Agenda cheia!\n");
                continue;
            }

            printf("\nNome: ");
            if (scanf(" %49[^\n]", agenda[total].nome) != 1) {
                printf("\nErro: Entrada interrompida!\n");
                return 0;
            }
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\nTelefone: ");
            if (scanf(" %19[^\n]", agenda[total].telefone) != 1) {
                printf("\nErro: Entrada interrompida!\n");
                return 0;
            }
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\nEmail: ");
            if (scanf(" %99[^\n]", agenda[total].email) != 1) {
                printf("\nErro: Entrada interrompida!\n");
                return 0;
            }
            while ((c = getchar()) != '\n' && c != EOF);
            
            if (strchr(agenda[total].nome, ';') != NULL || 
                strchr(agenda[total].telefone, ';') != NULL || 
                strchr(agenda[total].email, ';') != NULL) {
                printf("\nErro: Caractere ';' nao e permitido nos campos!\n");
                continue;
            }
            
            fptr = fopen("contatos.txt", "a"); 
            if (fptr != NULL) {
                fprintf(fptr, "%s;%s;%s\n", agenda[total].nome, agenda[total].telefone, agenda[total].email);
                fclose(fptr);
                
                printf("\n--- CONTATO ADICIONADO ---\n");
                printf("Nome guardado: %s\n", agenda[total].nome);
                printf("Telefone guardado: %s\n", agenda[total].telefone);
                printf("Email guardado: %s\n", agenda[total].email);
                
                total++;
            } else {
                printf("\nErro: Nao foi possivel salvar no arquivo!\n");
            }
        }
        else if(selec == 2){
    		printf("\n--- CONTATOS ADICIONADOS ---\n");
            if (total == 0) {
                printf("Nenhum contato encontrado.\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("Nome: %s\n", agenda[i].nome);
                    printf("Telefone: %s\n", agenda[i].telefone);
                    printf("Email: %s\n\n", agenda[i].email);
                }
            }
	    }
    }
}



/**Estrutura sugerida (você decide os detalhes)
Um menu: [1] Adicionar contato [2] Listar contatos [3] Sair
Usa a struct Contattoo que te passei (nome, telefone, email)
Um array de structs guarda os contatos enquan o programa roda
Ao adicionar, você escreve no arquivo também (não só na memória)
Ao abrir o programa (antes do menu aparecer), você lê o arquivo e preenche o array com o que já existia/

/*Programa pergunta nome, telefone, e-mail
Salva num arquivo .txt (ou você escolhe binário, se preferir)
Fecha o programa
Abre de novo → os contatos que você salvou antes aparecem automaticamente, sem precisar digitar tudo de novo
*/

/* printf("Digite a idade: ");
    scanf("%d", &p1.idade);*/
