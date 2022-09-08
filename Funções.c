#ifndef FUNCOES_TRABALHO_H_INCLUDED
#define FUNCOES_TRABALHO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char nome_aluno[50], curso_aluno[50], email_aluno[50];
    int matricula_aluno, ordem_aluno;
}aluno[10];

struct avaliador{
    char nome_avaliador[50], email_avaliador[50], instituicao[50];
    int ordem_avaliador;
}avaliador[10];

typedef struct Dados_Banca{
    char orientador[50], titulo_banca[50], local[50], resumo[50], horario[10];
    float porcentagem;
}dados_banca;

typedef struct Cadastro_banca {
    // Referente as informações dos alunos, avaliadores e banca
    struct aluno *alunos;
    struct avaliador *avaliadores;
    dados_banca *banca;

    int id_banca;
    int qtde_alunos;
    int qtde_avaliadores;

    // Mecanismo para unir as bancas
    struct Cadastro_banca *prox;
    struct Cadastro_banca *ant;
}cadastro_banca;

// Referências para a lista
cadastro_banca *inicio = NULL;
cadastro_banca *fim = NULL;
int qtde_bancas = 0;

void adicionar_banca();
void imprimir_bancas();
void remover_banca();
void atualizar_banca();

void adicionar_banca(){
    // Cria um nó de banca
    cadastro_banca *cadastrando = malloc(sizeof(cadastro_banca));

    // Numera quantos alunos serão adicionados
    printf("\nAcrescentará quantos alunos? ");
    scanf("%d", &cadastrando->qtde_alunos);

    // Aloca memória para alunos
    cadastrando->alunos = (struct aluno *) malloc(cadastrando->qtde_alunos*sizeof(struct aluno));

    for(int i=0; i<cadastrando->qtde_alunos; i++){
        int i_mais_um = i+1;
        printf("\nAluno %d\n", i_mais_um);
        printf("Nome..........: ");
        scanf(" %[^\n]s", cadastrando->alunos[i].nome_aluno);
        printf("matrícula.....: ");
        scanf("%d", &cadastrando->alunos[i].matricula_aluno);
        printf("Curso.........: ");
        scanf(" %[^\n]s", cadastrando->alunos[i].curso_aluno);
        printf("Email.........: ");
        scanf(" %[^\n]s", cadastrando->alunos[i].email_aluno);
        cadastrando->alunos[i].ordem_aluno = i_mais_um;
    }

    // Aloca memória para avaliadores
    cadastrando->avaliadores = (struct avaliador *) malloc(cadastrando->qtde_avaliadores*sizeof(struct avaliador));

    // Numera quantos avaliadores serão adiocnados
    printf("\nAcrescentará quantos avaliadores? ");
    scanf("%d", &cadastrando->qtde_avaliadores);

    for(int i=0; i<cadastrando->qtde_avaliadores; i++){
        int i_mais_um = i+1;
        printf("\nAvaliador %d\n", i_mais_um);
        printf("Nome..........: ");
        scanf(" %[^\n]s", cadastrando->avaliadores[i].nome_avaliador);
        printf("Instituição...: ");
        scanf(" %[^\n]s", cadastrando->avaliadores[i].instituicao);
        printf("Email.........: ");
        scanf(" %[^\n]s", cadastrando->avaliadores[i].email_avaliador);
        cadastrando->avaliadores[i].ordem_avaliador = i_mais_um;
    }

    // Aloca memória para o resto dos dados da banca
    cadastrando->banca = (dados_banca *) malloc(sizeof(dados_banca));

    printf("\nOrientador....: ");
    scanf(" %[^\n]s", cadastrando->banca->orientador);

    printf("\nTítulo........: ");
    scanf(" %[^\n]s", cadastrando->banca->titulo_banca);

    printf("\nResumo........: ");
    scanf(" %[^\n]s", cadastrando->banca->resumo);

    printf("\nHorário.......: ");
    scanf(" %[^\n]s", cadastrando->banca->horario);

    printf("\nLocal.........: ");
    scanf(" %[^\n]s", cadastrando->banca->local);

    printf("\nFrequência....: ");
    scanf("%f", &cadastrando->banca->porcentagem);

    cadastrando->prox = NULL;
    cadastrando->ant = NULL;

    // Aloca os elementos na lista
    if(inicio == NULL){ //lista vazia
        inicio = cadastrando;
        fim = cadastrando;
    }else{ // "no fim"
        cadastrando->ant = fim;
        fim->prox = cadastrando;
        fim = cadastrando;
    }
    qtde_bancas++;
    cadastrando->id_banca = qtde_bancas;
}

void imprimir_bancas(){
    if(inicio == NULL){ // Lista vazia!
        printf("\nNão há bancas cadastradas!\n");
    }else{
        // Inicia um ponteiro auxiliar no início
        cadastro_banca *aux = inicio;

        // loop printando as bancas
        for(int i=0; i < qtde_bancas; i++){
            int g = i+1;
            printf("\n\t<------ Banca %d ------>\n\n", g);

            printf("\t\tALUNO (%d)\n", aux->qtde_alunos);
            for (int i = 0; i < aux->qtde_alunos; i++){
                printf("Aluno %d.......: %s |", aux->alunos[i].ordem_aluno, aux->alunos[i].nome_aluno);
                printf(" %d |", aux->alunos[i].matricula_aluno);
                printf(" %s |", aux->alunos[i].curso_aluno);
                printf(" %s\n", aux->alunos[i].email_aluno);
            }

            printf("\n\t\tAVALIADOR (%d)\n", aux->qtde_avaliadores);
            for (int i = 0; i < aux->qtde_avaliadores; i++){
                printf("Avaliador %d...: %s |", aux->avaliadores[i].ordem_avaliador, aux->avaliadores[i].nome_avaliador);
                printf(" %s |", aux->avaliadores[i].email_avaliador);
                printf(" %s\n", aux->avaliadores[i].instituicao);
            }

            printf("\nOrientador....: %s\n", aux->banca->orientador);
            printf("Porcentagem...: %.2f\n", aux->banca->porcentagem);
            printf("Título........: %s\n", aux->banca->titulo_banca);
            printf("Resumo........: %s\n", aux->banca->resumo);
            printf("Horário.......: %s\n", aux->banca->horario);
            printf("Local.........: %s\n", aux->banca->local);
            // printf("ID: %d\n", aux->id_banca);
            printf("\n\t------- Banca %d -------\n", g);
        
            // Encaminha o aux para o próximo
            aux = aux->prox;
        }
    }
}

void remover_banca(){
    if(inicio!=NULL){
        int banca_escolhida;
        printf("\nQual banca será removida? ");
        scanf("%d", &banca_escolhida);

        if(banca_escolhida <= qtde_bancas && banca_escolhida > 0){
            cadastro_banca *lixo = inicio;
            if(inicio->id_banca == fim->id_banca){
                inicio = NULL;
                fim = NULL;
            }else{
                if(banca_escolhida == inicio->id_banca){
                    inicio->prox->ant = NULL;
                    inicio = inicio->prox;
                }else{
                    for(int i=0; i < (banca_escolhida-1); i++){
                        lixo = lixo->prox;
                    }
                    if(lixo->id_banca == fim->id_banca){
                        fim->ant->prox = NULL;
                        fim = fim->ant;
                    }else{
                        lixo->prox->ant = lixo->ant;
                        lixo->ant->prox = lixo->prox;
                        lixo->ant = NULL;
                        lixo->prox = NULL;
                    }
                }
            }
            // Libera a memória
            free(lixo);
            qtde_bancas--;

            // Diminui os id de cada banca
            cadastro_banca *aux = inicio;
            if(aux != NULL){
                if(banca_escolhida != (qtde_bancas+1)){
                    int atual = 1;
                    for(int i=0; i<qtde_bancas; i++){
                        aux->id_banca = atual;
                        atual++;
                        aux = aux->prox;
                    }
                }
            }
            printf("\n%d° banca removida!!\n", banca_escolhida);
        }else{ // Banca com id errado
            printf("\nNão há banca com esse número!\n");
        }
    }else{ // Lista vazia!
        printf("\nNão há bancas cadastradas!\n");
    }
}

void atualizar_banca(){
    if(inicio != NULL){
        int atualizar, alternativa_escolhida;
        printf("\nQual banca atualizar? ");
        scanf("%d", &atualizar);

        if(atualizar <= qtde_bancas && atualizar > 0){
            cadastro_banca *aux = inicio;

            int contador = 0;
            for(int i=0; i<(atualizar-1);i++){
                contador++;
                aux = aux->prox;
            }

            int plano_fuga = 0;
            while (plano_fuga == 0){
                printf("\n[1] Alunos\n[2] Avaliadores\n[3] Outros\n[4] Finalizar\nDigite sua escolha: ");
                scanf("%d", &alternativa_escolhida);

                switch (alternativa_escolhida){
                    // Atualiza os dados sobre alunos
                    case (1):
                        // Numera quantos alunos serão adicionados
                        printf("\nAcrescentará quantos alunos? ");
                        scanf("%d", &aux->qtde_alunos);

                        // Aloca memória para alunos
                        aux->alunos = (struct aluno *) malloc(aux->qtde_alunos*sizeof(struct aluno));

                        for(int i=0; i<aux->qtde_alunos; i++){
                            int i_mais_um = i+1;
                            printf("\nAluno %d\n", i_mais_um);
                            printf("Nome..........: ");
                            scanf(" %[^\n]s", aux->alunos[i].nome_aluno);
                            printf("matrícula.....: ");
                            scanf("%d", &aux->alunos[i].matricula_aluno);
                            printf("Curso.........: ");
                            scanf(" %[^\n]s", aux->alunos[i].curso_aluno);
                            printf("Email.........: ");
                            scanf(" %[^\n]s", aux->alunos[i].email_aluno);
                        }
                        break;

                    // Atualiza os dados sobre avaliadores
                    case (2):
                        // Aloca memória para avaliadores
                        aux->avaliadores = (struct avaliador *) malloc(aux->qtde_avaliadores*sizeof(struct avaliador));

                        // Numera quantos avaliadores serão adiocnados
                        printf("\nAcrescentará quantos avaliadores? ");
                        scanf("%d", &aux->qtde_avaliadores);

                        for(int i=0; i<aux->qtde_avaliadores; i++){
                            int i_mais_um = i+1;
                            printf("\nAvaliador %d\n", i_mais_um);
                            printf("Nome..........: ");
                            scanf(" %[^\n]s", aux->avaliadores[i].nome_avaliador);
                            printf("Instituição...: ");
                            scanf(" %[^\n]s", aux->avaliadores[i].instituicao);
                            printf("Email.........: ");
                            scanf(" %[^\n]s", aux->avaliadores[i].email_avaliador);
                        }
                        break;
                    
                    // Atualiza os dados sobre a banca
                    case (3):
                        // Aloca memória para o resto dos dados da banca
                        aux->banca = (dados_banca *) malloc(sizeof(dados_banca));

                        printf("\nOrientador....: ");
                        scanf(" %[^\n]s", aux->banca->orientador);

                        printf("\nTítulo........: ");
                        scanf(" %[^\n]s", aux->banca->titulo_banca);

                        printf("\nResumo........: ");
                        scanf(" %[^\n]s", aux->banca->resumo);

                        printf("\nHorário.......: ");
                        scanf(" %[^\n]s", aux->banca->horario);

                        printf("\nLocal.........: ");
                        scanf(" %[^\n]s", aux->banca->local);

                        printf("\nFrequência....: ");
                        scanf("%f", &aux->banca->porcentagem);
                    break;
                    

                    case (4):
                        printf("\nConcluído!\n");
                        plano_fuga++;
                        break;
                    
                    default:
                        printf("\nOperação de atualização inválida!\n");
                        break;
                }
            }
        }else{ // Caso a banca escolhida não exista
            printf("\nNão há banca com esse número!\n");
        }
    }else{ // Lista vazia!
        printf("\nNão há bancas cadastradas!\n");
    }
}

#endif // FUNCOES_TRABALHO_H_INCLUDED
