#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

int main() {
    int opcao;
    printf("===== SISTEMA DE CONSULTÓRIO MÉDICO =====\n");

    if (!loginFuncionario()) {
        printf("Login falhou. Encerrando programa.\n");
        return 0;
    }

    char profissao[20];
    obterProfissao(profissao); // Médico ou Recepção

    if (strcmp(profissao, "Recepcao") == 0) {
        // menu da recepção
        menuRecepcao();
    } else if (strcmp(profissao, "Medico") == 0) {
        // menu do médico
        menuMedico();
    } else {
        printf("Profissão inválida.\n");
    }

    return 0;
}
