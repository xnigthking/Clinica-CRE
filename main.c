#include <stdio.h>
#include <string.h>
// funcao cadastrar funcionario
// funcao imprimir nota fiscal
// funcao imprimir atestado

int main()
{
    char codigoFuncionario[50];
    char senha[50];

    printf("============================================================================\n");
    printf("=                                Clinica CRE                               =\n");
    printf("=          'Centro de Reabilitação Esportivo Profissional e Amador'        =\n");
    printf("============================================================================\n");

    printf("\n");
    printf("digite seu codigo: ");
    scanf("%s", &codigoFuncionario);
    printf("digite a sua senha: ");
    scanf("%s", &senha);
    getchar();

    if (codigoFuncionario == "rep123" && senha == "rep123")
    {
        printf("Area recepcao! ");
    }
    else if (codigoFuncionario == "medic123" && senha == "medic123")
    {
        printf("Area do medico! ");
    }
    else
    {
        printf("Senha ou login incorreto!");
    }
    printf("Sistema finalizado");
    return 0;
}