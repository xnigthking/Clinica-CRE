#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"

void agendarConsulta() {
    FILE *file = fopen("dados/consultas.txt", "a");
    if (!file) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    Consulta c;
    printf("\n=== Agendar Consulta ===\n");
    printf("CPF do Paciente: ");
    scanf("%s", c.cpfPaciente);
    printf("Data (dd/mm/aaaa): ");
    scanf("%s", c.data);
    printf("Horário (hh:mm): ");
    scanf("%s", c.horario);
    printf("Problema relatado: ");
    getchar(); // limpar buffer
    fgets(c.problema, 100, stdin);
    c.problema[strcspn(c.problema, "\n")] = '\0'; // remover newline

    strcpy(c.realizada, "Nao"); // por padrão, ainda não realizada

    fprintf(file, "%s|%s|%s|%s|%s\n", c.cpfPaciente, c.data, c.horario, c.problema, c.realizada);
    fclose(file);

    printf("Consulta agendada com sucesso!\n");
}

void listarConsultas() {
    FILE *file = fopen("dados/consultas.txt", "r");
    if (!file) {
        printf("Nenhuma consulta agendada.\n");
        return;
    }

    Consulta c;
    printf("\n=== Lista de Consultas ===\n");
    while (fscanf(file, "%14[^|]|%10[^|]|%5[^|]|%99[^|]|%3[^\n]\n",
                  c.cpfPaciente, c.data, c.horario, c.problema, c.realizada) == 5) {
        printf("CPF: %s | Data: %s | Horário: %s | Problema: %s | Realizada: %s\n",
               c.cpfPaciente, c.data, c.horario, c.problema, c.realizada);
    }

    fclose(file);
}

void listarConsultasPendentes() {
    FILE *file = fopen("dados/consultas.txt", "r");
    if (!file) {
        printf("Nenhuma consulta encontrada.\n");
        return;
    }

    Consulta c;
    int encontrou = 0;
    printf("\n=== Consultas Não Realizadas ===\n");
    while (fscanf(file, "%14[^|]|%10[^|]|%5[^|]|%99[^|]|%3[^\n]\n",
                  c.cpfPaciente, c.data, c.horario, c.problema, c.realizada) == 5) {
        if (strcmp(c.realizada, "Nao") == 0) {
            printf("CPF: %s | Data: %s | Hora: %s | Problema: %s\n",
                   c.cpfPaciente, c.data, c.horario, c.problema);
            encontrou = 1;
        }
    }

    fclose(file);
    if (!encontrou) {
        printf("Nenhuma consulta pendente.\n");
    }
}

void marcarConsultaComoRealizada() {
    FILE *file = fopen("dados/consultas.txt", "r");
    FILE *temp = fopen("dados/temp.txt", "w");

    if (!file || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    Consulta c;
    char cpfBusca[15], dataBusca[11];
    int atualizado = 0;

    printf("CPF do paciente: ");
    scanf("%s", cpfBusca);
    printf("Data da consulta: ");
    scanf("%s", dataBusca);

    while (fscanf(file, "%14[^|]|%10[^|]|%5[^|]|%99[^|]|%3[^\n]\n",
                  c.cpfPaciente, c.data, c.horario, c.problema, c.realizada) == 5) {

        if (strcmp(c.cpfPaciente, cpfBusca) == 0 && strcmp(c.data, dataBusca) == 0) {
            strcpy(c.realizada, "Sim");
            atualizado = 1;
        }

        fprintf(temp, "%s|%s|%s|%s|%s\n", c.cpfPaciente, c.data, c.horario, c.problema, c.realizada);
    }

    fclose(file);
    fclose(temp);

    remove("dados/consultas.txt");
    rename("dados/temp.txt", "dados/consultas.txt");

    if (atualizado)
        printf("Consulta marcada como realizada.\n");
    else
        printf("Consulta não encontrada.\n");
}

void relatorioConsultasPorPaciente() {
    char cpfBusca[15];
    Consulta c;
    int encontrou = 0;

    printf("\n=== Relatório de Consultas por Paciente ===\n");
    printf("Informe o CPF do paciente: ");
    scanf("%s", cpfBusca);

    FILE *file = fopen("dados/consultas.txt", "r");
    if (!file) {
        printf("Erro ao abrir consultas.txt.\n");
        return;
    }

    while (fscanf(file, "%14[^|]|%10[^|]|%5[^|]|%99[^|]|%3[^\n]\n",
                  c.cpfPaciente, c.data, c.horario, c.problema, c.realizada) == 5) {
        if (strcmp(c.cpfPaciente, cpfBusca) == 0) {
            printf("Data: %s | Hora: %s | Problema: %s | Realizada: %s\n",
                   c.data, c.horario, c.problema, c.realizada);
            encontrou = 1;
        }
    }

    fclose(file);

    if (!encontrou)
        printf("Nenhuma consulta encontrada para este CPF.\n");
}
