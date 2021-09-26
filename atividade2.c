
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int anoNasc;
    float gastosM;
} cliente; // definicao da struct

int main()
{
    cliente *clientes;
    clientes = malloc(10 * sizeof(cliente));
    int tamanho = 10;
    int x = 0;
    int indice = 0;
    while (1)
    {
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
            for (int i = 0; i < (indice + 1); i++)
            {
                if (strcmp(nome, clientes[i].nome) == 0)
                {
                    posicao = i;
                    break;
                }
            }
            if (posicao == -1)
            {
                printf("\nNao foi encontrado nenhum cliente com esse NOME!\n");
            }
            else
            {
                for (int i = posicao; i < (indice + 1); i++)
                {
                    clientes[i] = clientes[i + 1];
                }
                printf("Cliente deletado com sucesso!");
            }
        }
        else if (x == 3)
        {
            char nome1[30] = "NULL";
            int posicao1 = -1;
            float gastoAd = 0.0;
            printf("\nDigite o nome do cliente que deseja atualizar os gastos: ");
            scanf("%s", &nome1);
            for (int i = 0; i < (indice + 1); i++)
            {
                if (strcmp(nome1, clientes[i].nome) == 0)
                {
                    posicao1 = i;
                    break;
                }
            }
            if (posicao1 == -1)
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
            int posicao2 = -1;
            printf("\nDigite o nome do cliente que deseja zerar os gastos: ");
            scanf("%s%*c", nome2);
            for (int i = 0; i < (indice + 1); i++)
            {
                if (strcmp(nome2, clientes[i].nome) == 0)
                {
                    posicao2 = i;
                    break;
                }
            }
            if (posicao2 == -1)
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
            int posicao3 = -1;
            printf("\nDigite o nome do cliente que deseja mostrar os dados: ");
            scanf("%s%*c", nome3);
            for (int i = 0; i < (indice + 1); i++)
            {
                if (strcmp(nome3, clientes[i].nome) == 0)
                {
                    posicao3 = i;
                    break;
                }
            }
            if (posicao3 == -1)
            {
                printf("\nNao foi encontrado nenhum cliente com esse NOME!\n");
            }
            else
            {
                printf("\nNome: %s", clientes[posicao3].nome);
                printf("\nAno de nascimento: %d", clientes[posicao3].anoNasc);
                printf("\nValor gasto nesse mes: R$%.2f", clientes[posicao3].gastosM);
            }
        }
        else
        {
            printf("\n Por favor digite uma opção valida!");
        }
        int userR = 0;
        printf("\nDeseja realizar mais alguma operacao? Use 0 para NAO e 1 para SIM: ");
        scanf("%d", &userR);
        if (userR == 0)
        {
            free(clientes);
            break;
        }
        if ((indice + 1) == tamanho)
        {
            clientes = realloc(clientes, 10 * sizeof(cliente));
            tamanho += 10;
        }
    }
}