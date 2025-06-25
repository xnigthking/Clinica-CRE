#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laudo.h"

void emitirLaudo() {
    FILE *file = fopen("dados/laudos.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo de laudos.\n");
        return;
    }

    char cpf[15];
    char laudo[200];
    printf("CPF do paciente: ");
    scanf("%s", cpf);
    printf("Laudo médico: ");
    getchar(); // limpar buffer
    fgets(laudo, 200, stdin);
    laudo[strcspn(laudo, "\n")] = 0;

    fprintf(file, "CPF: %s | Laudo: %s\n", cpf, laudo);
    fclose(file);
    printf("Laudo registrado.\n");
}

void emitirAtestado() {
    FILE *file = fopen("dados/atestados.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo de atestados.\n");
        return;
    }

    char cpf[15];
    int dias;
    printf("CPF do paciente: ");
    scanf("%s", cpf);
    printf("Dias de repouso recomendados: ");
    scanf("%d", &dias);

    fprintf(file, "CPF: %s | Dias: %d\n", cpf, dias);
    fclose(file);
    printf("Atestado registrado.\n");
}
