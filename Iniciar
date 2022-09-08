#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_trabalho.c"

int main(){
    // Loop para rodar o sistema
    while(1){
        char escolha;
        printf("\n[C] Cadastrar\n[E] Exibir\n[A] Atualizar\n[R] Remover\n");
        printf("Escolha uma operação: ");
        // escolha = getchar();
        scanf(" %c", &escolha);

        switch (escolha){
            case ('c'):
                adicionar_banca();
                break;

            case ('C'):
                adicionar_banca();
                break;

            case ('e'):
                imprimir_bancas();
                break;

            case ('E'):
                imprimir_bancas();
                break;

            case ('r'):
                remover_banca();
                break;

            case ('R'):
                remover_banca();
                break;

            case ('a'):
                atualizar_banca();
                break;

            case ('A'):
                atualizar_banca();
                break;

            default:
                printf("\nOperação Inválida!\n");
                break;
        }

    //     if(escolha == 'c' || escolha == 'C'){
    //         adicionar_banca();
    //     }else if(escolha == 'e' || escolha == 'E'){
    //         imprimir_bancas();
    //     }else if(escolha == 'r' || escolha == 'R'){
    //         remover_banca();
    //     }else{
    //         printf("Não é uma operação válida!\n");
    //     }
    }

    return 0;
}
