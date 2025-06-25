#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "paciente.h"
#include "consulta.h"
#include "laudo.h"


#define MAX 100

typedef struct {
    char usuario[30];
    char senha[20];
    char profissao[20]; // "Medico" ou "Recepcao"
} Funcionario;

void cadastrarFuncionario() {
    FILE *file = fopen("dados/funcionarios.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo de funcionarios.\n");
        return;
    }

    Funcionario f;
    printf("=== Cadastro de Funcionário ===\n");
    printf("Usuário: ");
    scanf("%s", f.usuario);
    printf("Senha: ");
    scanf("%s", f.senha);
    printf("Profissão (Medico ou Recepcao): ");
    scanf("%s", f.profissao);

    fprintf(file, "%s %s %s\n", f.usuario, f.senha, f.profissao);
    fclose(file);
    printf("Funcionário cadastrado com sucesso!\n");
}

int loginFuncionario() {
    char usuario[30], senha[20];
    printf("=== Login do Funcionário ===\n");
    printf("Usuário: ");
    scanf("%s", usuario);
    printf("Senha: ");
    scanf("%s", senha);

    FILE *file = fopen("dados/funcionarios.txt", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return 0;
    }

    Funcionario f;
    while (fscanf(file, "%s %s %s", f.usuario, f.senha, f.profissao) != EOF) {
        if (strcmp(usuario, f.usuario) == 0 && strcmp(senha, f.senha) == 0) {
            fclose(file);
            FILE *sessao = fopen("dados/sessao.txt", "w");
            fprintf(sessao, "%s\n", f.profissao);
            fclose(sessao);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void obterProfissao(char *profissao) {
    FILE *sessao = fopen("dados/sessao.txt", "r");
    if (!sessao) {
        printf("Erro ao obter profissão da sessão.\n");
        strcpy(profissao, "Desconhecido");
        return;
    }

    fscanf(sessao, "%s", profissao);
    fclose(sessao);
}

void menuRecepcao() {
    int opcao;
    do {
        printf("\n--- Menu Recepção ---\n");
        printf("[1] Cadastrar paciente\n");
        printf("[2] Listar pacientes\n");
        printf("[3] Agendar consulta\n");
        printf("[4] Listar consultas\n");
        printf("[5] Editar paciente\n");
        printf("[6] Relatório por paciente\n");
        printf("[0] Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                listarPacientes();
                break;
            case 3:
                agendarConsulta();
                break;
            case 4:
                listarConsultas();
                break;
            case 5:
                printTitulo("Editar Paciente");
                editarPaciente();
                pausar();
                break;
            case 6:
                printTitulo("Relatório de Consultas por Paciente");
                relatorioConsultasPorPaciente();
                pausar();
                break;                
            case 0:
                printf("Saindo do menu da recepção.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}


void menuMedico() {
    int opcao;
    do {
        printf("\n--- Menu Médico ---\n");
        printf("[1] Ver agenda (não realizadas)\n");
        printf("[2] Marcar consulta como realizada\n");
        printf("[3] Emitir laudo\n");
        printf("[4] Emitir atestado\n");
        printf("[0] Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarConsultasPendentes();
                break;
            case 2:
                marcarConsultaComoRealizada();
                break;
            case 3:
                emitirLaudo();
                break;
            case 4:
                emitirAtestado();
                break;
            case 0:
                printf("Saindo do menu do médico.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}
