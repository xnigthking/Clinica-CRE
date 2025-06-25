#include <stdio.h> // Para entrada e saída (printf, scanf)
#include <string.h> // Para manipulação de strings (strcmp, strcpy)
#include <stdbool.h> // Para tipo booleano (true/false)

// --- Estruturas de Dados ---
typedef struct {
    char login[50];
    char senha[50];
    char profissao[50]; // "Medico" ou "Recepcao"
    char nome[100];
} Funcionario;

// --- Variáveis Globais (para este exemplo simples) ---
Funcionario funcionarios[100]; // Capacidade máxima de 100 funcionários
int num_funcionarios = 0; // Contador de funcionários cadastrados

// --- Funções Auxiliares ---

// Função para limpar o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Funções do Fluxograma ---

// 1. Função de Cadastro de Funcionário
void cadastrar_funcionario() {
    if (num_funcionarios >= 100) {
        printf("Limite de funcionários atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR NOVO FUNCIONÁRIO ---\n");
    printf("Nome: ");
    limpar_buffer(); // Limpa o buffer antes de ler a string
    fgets(funcionarios[num_funcionarios].nome, sizeof(funcionarios[num_funcionarios].nome), stdin);
    funcionarios[num_funcionarios].nome[strcspn(funcionarios[num_funcionarios].nome, "\n")] = 0; // Remove o newline

    printf("Login: ");
    fgets(funcionarios[num_funcionarios].login, sizeof(funcionarios[num_funcionarios].login), stdin);
    funcionarios[num_funcionarios].login[strcspn(funcionarios[num_funcionarios].login, "\n")] = 0;

    printf("Senha: ");
    fgets(funcionarios[num_funcionarios].senha, sizeof(funcionarios[num_funcionarios].senha), stdin);
    funcionarios[num_funcionarios].senha[strcspn(funcionarios[num_funcionarios].senha, "\n")] = 0;

    printf("Profissão (Medico ou Recepcao): ");
    fgets(funcionarios[num_funcionarios].profissao, sizeof(funcionarios[num_funcionarios].profissao), stdin);
    funcionarios[num_funcionarios].profissao[strcspn(funcionarios[num_funcionarios].profissao, "\n")] = 0;

    printf("Funcionário cadastrado com sucesso!\n");
    num_funcionarios++;
}

// 2. Função de Login para o Funcionário
// Retorna o índice do funcionário logado, ou -1 se o login falhar
int login_funcionario() {
    char login_digitado[50];
    char senha_digitada[50];
    int i;

    printf("\n--- LOGIN DO FUNCIONÁRIO ---\n");
    printf("Login: ");
    limpar_buffer();
    fgets(login_digitado, sizeof(login_digitado), stdin);
    login_digitado[strcspn(login_digitado, "\n")] = 0;

    printf("Senha: ");
    fgets(senha_digitada, sizeof(senha_digitada), stdin);
    senha_digitada[strcspn(senha_digitada, "\n")] = 0;

    for (i = 0; i < num_funcionarios; i++) {
        if (strcmp(funcionarios[i].login, login_digitado) == 0 &&
            strcmp(funcionarios[i].senha, senha_digitada) == 0) {
            printf("Login bem-sucedido! Bem-vindo(a), %s.\n", funcionarios[i].nome);
            return i; // Retorna o índice do funcionário logado
        }
    }

    printf("Login ou senha incorretos.\n");
    return -1; // Retorna -1 se o login falhar
}

// --- Função Principal (main) ---
int main() {
    int opcao;
    int indice_funcionario_logado = -1; // -1 significa ninguém logado

    // O loop principal do programa
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Fazer Login \n");
        printf("2. Cadastrar Novo Funcionário \n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                indice_funcionario_logado = login_funcionario(); // Tenta fazer login
                if (indice_funcionario_logado != -1) {
                    // Se o login for bem-sucedido, podemos prosseguir com as funcionalidades
                    // baseadas na profissão. Por enquanto, apenas exibimos a profissão.
                    printf("Profissão: %s \n", funcionarios[indice_funcionario_logado].profissao);
                    // Aqui você chamaria as funções específicas para Médico ou Recepção
                    // Por exemplo: if (strcmp(funcionarios[indice_funcionario_logado].profissao, "Medico") == 0) { // chamar_funcoes_medico(); }
                    // else { // chamar_funcoes_recepcao(); }
                }
                break;
            case 2:
                cadastrar_funcionario(); // Chama a função de cadastro 
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}