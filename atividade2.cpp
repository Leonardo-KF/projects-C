#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
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
        int tamanho = (sizeof(clientes) / sizeof(clientes[0]));
        printf("\n=============================================\n");
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
            indice++;
        }
        else if (x == 2)
        {
            char nome[30];
            int posicao = 0;
            printf("\nDigite o nome do cliente que deseja deletar: ");
            scanf("%s", &nome);
            for (int i = 0; i < tamanho; i++)
            {
                if (strcmp(nome, clientes[i].nome) == 0)
                {
                    posicao = i;
                    break;
                }
            }
            if (posicao == 0)
            {
                printf("\nNao foi encontrado nenhum cliente com esse NOME!\n");
            }
            else
            {
                for (int i = posicao; i < tamanho; i++)
                {
                    clientes[i] = clientes[i + 1];
                }
                printf("Cliente deletado com sucesso!");
            }
        }
        else if (x == 3)
        {
            char nome1[30];
            int posicao1 = 0;
            int gastoAd = 0;
            printf("\nDigite o nome do cliente que deseja atualizar os gastos: ");
            scanf("%s", &nome1);
            for (int i = 0; i < tamanho; i++)
            {
                if (strcmp(nome1, clientes[i].nome) == 0)
                {
                    posicao1 = i;
                    break;
                }
            }
            if (posicao1 == 0)
            {
                printf("\nNao foi encontrado nenhum cliente com esse NOME!\n");
            }
            else
            {
                printf("\nDigite o valor que sera adcionado aos gastos do cliente: ");
                scanf("%f", &gastoAd);
                clientes[posicao1].gastosM += gastoAd;
                printf("\nValor adcionado com sucesso!");
            }
        }
        else if (x == 4)
        {
            char nome2[30];
            int posicao2 = 0;
            printf("\nDigite o nome do cliente que deseja zerar os gastos: ");
            scanf("%s", &nome2);
            for (int i = 0; i < tamanho; i++)
            {
                if (strcmp(nome2, clientes[i].nome) == 0)
                {
                    posicao2 = i;
                    break;
                }
            }
            if (posicao2 == 0)
            {
                printf("\nNao foi encontrado nenhum cliente com esse NOME!\n");
            }
            else
            {
                clientes[posicao2].gastosM = 0;
                printf("\nGastos zerados com sucesso!");
            }
        }
        else if (x == 5)
        {
            char nome3[30];
            int posicao3 = 0;
            printf("\nDigite o nome do cliente que deseja deletar: ");
            scanf("%s", &nome3);
            for (int i = 0; i < tamanho; i++)
            {
                if (strcmp(nome3, clientes[i].nome) == 0)
                {
                    posicao3 = i;
                    break;
                }
            }
            if (posicao3 == 0)
            {
                printf("\nNao foi encontrado nenhum cliente com esse NOME!\n");
            }
            else
            {
                printf("\nNome: %s", clientes[posicao3].nome);
                printf("\nAno de nascimento: %d", clientes[posicao3].anoNasc);
                printf("\nValor gasto nesse mes: %.2f", clientes[posicao3].gastosM);
            }
        }
        int userR = 0;
        printf("\nDeseja realizar mais alguma operacao? Use 0 para NAO e 1 para SIM: ");
        scanf("%d", &userR);
        if (userR == 0)
        {
            break;
        }
    }
}