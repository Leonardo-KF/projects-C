#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nome[30];
    int anoNasc;
    float gastosM;
} cliente; // definicao da struct
cliente clientes[10];

int main()
{
    int x = 0;
    int indice = 0;
    while (true)
    {

        printf("=============================================\n");
        printf("            Cadastro de clientes!\n");
        printf("-------< MENU DE OPCOES >-------\n");
        printf("1 - Adcionar um cliente.\n");
        printf("2 - Deletar cliente.\n");
        printf("3 - Atualizar gasto mensal do cliente.\n");
        printf("4 - Limpar os gastos dos clientes.\n");
        printf("5 - Exibir os gastos de um cliente. \n");
        printf("=============================================\n");
        printf("\nPor favor digite a opcao desejada: ");
        scanf("%d", &x);

        if (x == 1)
        {
            printf("\nDigite o nome do cliente: ");
            scanf("%s%*c", clientes[indice].nome);
            printf("\nDigite o ano de nascimento do cliente: ");
            scanf("%d", &clientes[indice].anoNasc);
            printf("\nDigite o gasto do cliente: ");
            scanf("%f", &clientes[indice].gastosM);
            clientes[indice].id = indice;
            indice++;
        }
    }
}