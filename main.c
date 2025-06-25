#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// funcao cadastrar funcionario
// funcao imprimir nota fiscal
// funcao imprimir atestado

int main()
{
    char codigoFuncionario[50];
    char senha[50];

    system("cls");
    printf("============================================================================\n");
    printf("                                Clinica CRE                                 \n");
    printf("         'Centro de Reabilitação Esportivo Profissional e Amador'           \n");
    printf("============================================================================\n");

    printf("\n");
    printf("digite seu codigo: ");
    fgets(codigoFuncionario, sizeof(codigoFuncionario), stdin);
    strtok(codigoFuncionario, "\n");
    printf("digite a sua senha: ");
    fgets(senha, sizeof(senha), stdin);
    strtok(senha, "\n"); 

    if (strcmp(codigoFuncionario, "rep123") == 0 && strcmp(senha, "rep123") == 0)
    {
        printf("Area recepcao! ");
    }
    else if (strcmp(codigoFuncionario, "medic123") == 0 && strcmp(senha, "medic123") == 0)
    {
        printf("Area do medico! ");
    }
    else
    {
        printf("Senha ou login incorreto!\n");
    }
    printf("Sistema finalizado\n");
    return 0;
}
