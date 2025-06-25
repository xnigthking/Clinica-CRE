#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

void cadastrarPaciente() {
    FILE *file = fopen("dados/pacientes.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo de pacientes.\n");
        return;
    }

    Paciente p;
    printf("\n=== Cadastro de Paciente ===\n");
    printf("Nome: ");
    getchar(); // limpar buffer
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0; // remover newline
    printf("CPF: ");
    scanf("%s", p.cpf);
    printf("Idade: ");
    scanf("%d", &p.idade);
    printf("Telefone: ");
    scanf("%s", p.telefone);

    fprintf(file, "%s|%s|%d|%s\n", p.nome, p.cpf, p.idade, p.telefone);
    fclose(file);

    printf("Paciente cadastrado com sucesso!\n");
}

void listarPacientes() {
    FILE *file = fopen("dados/pacientes.txt", "r");
    if (!file) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }

    Paciente p;
    printf("\n=== Lista de Pacientes ===\n");
    while (fscanf(file, " %49[^|]|%14[^|]|%d|%19[^\n]\n", p.nome, p.cpf, &p.idade, p.telefone) == 4) {
        printf("Nome: %s | CPF: %s | Idade: %d | Telefone: %s\n", p.nome, p.cpf, p.idade, p.telefone);
    }

    fclose(file);
}

void editarPaciente() {
    char cpfBusca[15];
    int encontrado = 0;
    Paciente p;

    printf("\n=== Editar Paciente ===\n");
    printf("Informe o CPF do paciente: ");
    scanf("%s", cpfBusca);

    FILE *arquivo = fopen("dados/pacientes.txt", "r");
    FILE *temp = fopen("dados/temp.txt", "w");

    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    while (fscanf(arquivo, " %49[^|]|%14[^|]|%d|%19[^\n]\n", p.nome, p.cpf, &p.idade, p.telefone) == 4) {
        if (strcmp(p.cpf, cpfBusca) == 0) {
            encontrado = 1;
            printf("Paciente encontrado!\n");
            printf("Novo nome: ");
            getchar(); // limpa buffer
            fgets(p.nome, 50, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;

            printf("Nova idade: ");
            scanf("%d", &p.idade);

            printf("Novo telefone: ");
            scanf("%s", p.telefone);
        }
        fprintf(temp, "%s|%s|%d|%s\n", p.nome, p.cpf, p.idade, p.telefone);
    }

    fclose(arquivo);
    fclose(temp);
    remove("dados/pacientes.txt");
    rename("dados/temp.txt", "dados/pacientes.txt");

    if (encontrado)
        printf("Dados do paciente atualizados com sucesso!\n");
    else
        printf("Paciente não encontrado.\n");
}
