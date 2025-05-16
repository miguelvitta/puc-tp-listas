// Aimê Couto, Lucas Duarte, Miguel Vitta
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 31
#define MAX_STRUCT 10
#define MAX_NOME 101
#define MAX_PASSOS 20
#define MAX_INGREDIENTES 15

typedef struct {
    char nome[MAX_CHAR];
    float qtde;
} ingredientes;

typedef struct{
    char nome[MAX_CHAR];
    int qtde_ingredientes;
    ingredientes ingrediente[MAX_INGREDIENTES];
    int qtde_passos;
    char passos[MAX_PASSOS][MAX_NOME];
} receita;

void criar_receita(receita* r);
void imprimir_receita(receita *r);
int buscar_receita(receita* receitas, int total_receitas, char* nome);

int main() {
    receita receitas[MAX_STRUCT];
    int total_receitas = 0;
    for (int i = 0; i < MAX_STRUCT; i++) {
            printf("Nome da Receita:\n");
            char nome[MAX_CHAR];
            fgets(nome, MAX_CHAR, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            if(strcmp(nome, "fim") == 0){
                break;
            }
            strcpy(receitas[total_receitas].nome, nome);
            criar_receita(&receitas[total_receitas]);
            total_receitas++;
            printf("Digite \"fim\" para encerrar.");
    }


    char nome[MAX_CHAR];
    printf("Digite o nome da receita que deseja buscar: ");
    fgets(nome, sizeof(nome), stdin);

    int posicao = buscar_receita(receitas, total_receitas, nome);
    if (posicao >= 0) {
        imprimir_receita(&receitas[posicao]);
    } else {
        printf("Receita não encontrada.\n");
    }

    return 0;
}

void criar_receita(receita* r) {
    printf("Quantidade de ingredientes: ");
    scanf("%d", &r->qtde_ingredientes);
    while (getchar() != '\n');

    for (int i = 0; i < r->qtde_ingredientes; i++) {
        printf("Entre o nome do ingrediente: ");
        fgets(r->ingrediente[i].nome, sizeof(r->ingrediente[i].nome), stdin);
        while (getchar() != '\n');

        printf("Entre a quantidade deste ingrediente: ");
        scanf("%f", &r->ingrediente[i].qtde);
        while (getchar() != '\n');
    }

    printf("Quantidade de passos:\n");
    scanf("%d", &r->qtde_passos);

    for (int i = 0; i < r->qtde_passos; i++) {
        printf("Digite o passo: ");
        fgets(r->passos[i], sizeof(r->passos[i]), stdin);
        while (getchar() != '\n');
    }
}

void imprimir_receita(receita *r) {
    printf("==================================================\n");
    printf("Receita: %s\n", r->nome);
    printf("--------------------------------------------------\n");
    printf("Ingredientes:\n");
    for (int i = 0; i < r->qtde_ingredientes; i++) {
        printf("%.1f x %s\n", r->ingrediente[i].qtde, r->ingrediente[i].nome);
    }
    printf("--------------------------------------------------\n");
    printf("Passos:\n");
    for (int i = 0; i < r->qtde_passos; i++) {
        printf("%d. %s\n", i + 1, r->passos[i]);
    }
    printf("==================================================\n");
}

int buscar_receita(receita* receitas, int total_receitas, char* nome){
    for(int i = 0; i < total_receitas; i++){
        if(strcmp(receitas[i].nome, nome)==0){
            return i;
        }
    }
    return 0;
}
