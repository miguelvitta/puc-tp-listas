#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 101

typedef struct {
    char nome[NAME_SIZE];
    int matricula;
    float n1;
    float n2;
    float media;
} aluno;

typedef struct {
    aluno alunos[10];
} sala;

sala* createVector(int* n);
void calculateAverage(sala* tp, int* n);
void printResults(sala* tp, int* n);

int main () {
    int n = 0;

    sala* tp = createVector(&n);

    calculateAverage(tp, &n);

    printResults(tp, &n);

    free(tp);
    return 0;
}

sala* createVector(int* n) {
    FILE* pfile = NULL;
    
    pfile = fopen("alunos.txt", "r");

    fscanf(pfile, "%d", n);

    sala *tp = calloc(*n ,sizeof(sala));
    for (int i = 0; i < *n; i++) {
        fscanf(pfile, "%d %s", &tp->alunos[i].matricula, tp->alunos[i].nome);
    }
    fclose(pfile);

    pfile = fopen("n1.txt", "r");
    for (int i = 0; i < *n; i++) {
        int x = tp->alunos[i].matricula;
        int trash = 0;
        float n1 = 0;
        fscanf(pfile, "%d %f", &trash, &n1);
        for (int j = 0; j < *n; j++) {
            if (tp->alunos[i].matricula == x) {
                tp->alunos[i].n1 = n1;
            }
        }
    }
    fclose(pfile);

    pfile = fopen("n2.txt", "r");
    for (int i = 0; i < *n; i++) {
        int x = tp->alunos[i].matricula;
        int trash = 0;
        float n2 = 0;
        fscanf(pfile, "%d %f", &trash, &n2);
        for (int j = 0; j < *n; j++) {
            if (tp->alunos[i].matricula == x) {
                tp->alunos[i].n2 = n2;
            }
        }
    }
    fclose(pfile);

    return tp;
}

void calculateAverage(sala* tp, int* n) {
    for (int i = 0; i < *n; i++) {
        tp->alunos[i].media = (tp->alunos[i].n1 * 0.4) + (tp->alunos[i].n1 * 0.6);
    }
}


void printResults(sala* tp, int* n) {
    FILE* pfile = NULL;
    pfile = fopen("resultados.txt", "w+");
    for (int i = 0; i < *n; i++) {
        fprintf(pfile, "%d %s ", tp->alunos[i].matricula, tp->alunos[i].nome);
        (tp->alunos[i].media >= 6) ? fprintf(pfile, "APROVADO\n"): fprintf(pfile, "REPROVADO\n");
    }
    fclose(pfile);
}