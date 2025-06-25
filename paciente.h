#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[50];
    char cpf[15];
    int idade;
    char telefone[20];
} Paciente;

void cadastrarPaciente();
void listarPacientes();
void editarPaciente();

#endif
