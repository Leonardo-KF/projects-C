#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char marca[40];
    char modelo[40];
    int AnoFab;
    char placa[8];
} carros; //definicao da struct
carros carro[10];

int main()
{
    int indice = 0;
    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        strcpy(carro[i].marca, "NULL");
        strcpy(carro[i].modelo, "NULL");
        carro[i].AnoFab = 0;
        strcpy(carro[i].placa, "NULL");
    }
    while (true)
    {
        printf("=============================================\n");
        printf("            Cadastro de veiculos!\n");
        printf("-------< MENU DE OPCOES >-------\n");
        printf("1 - Listar os veiculos cadastrados.\n");
        printf("2 - Cadastrar um novo veiculo.\n");
        printf("3 - Listar os veiculos por ano de fabricacao.\n");
        printf("4 - Listar os veiculos a partir do ano de fabricacao de sua preferencia.\n");
        printf("5 - Listar os veiculos do modelo desejado. \n");
        printf("=============================================\n");
        printf("\nPor favor digite a opcao desejada: ");
        scanf("%d", &x);
        if (x == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                if (strcmp("NULL", carro[i].marca) == 0)
                {
                    printf("\nNenhum veiculo registrado\n");
                    break;
                }
                else
                {
                    printf("\nA marca do veiculo: %s", carro[i].marca);
                    printf("\nO modelo do veiculo: %s", carro[i].modelo);
                    printf("\nO ano do veiculo: %d", carro[i].AnoFab);
                    printf("\nA placa do veiculo: %s", carro[i].placa);
                }
            }
        }
        else if (x == 2)
        {
            printf("\nDigite a marca do veiculo: ");
            scanf("%s%*c", carro[indice].marca);
            printf("\nDigite o modelo do veiculo: ");
            scanf("%s%*c", carro[indice].modelo);
            printf("\nDigite o ano de fabricacao do veiculo: ");
            scanf("%d", &carro[indice].AnoFab);
            printf("\nDigite a placa do veiculo no formato XXX-YYYY: ");
            scanf("%s%*c", carro[indice].placa);
            indice++;
        }
        else if (x == 3)
        {
            int control = 0;
            int ano = 0;
            printf("\nDigite o ano dos veiculos que deseja pesquisar no formato AAAA: ");
            scanf("%d", &ano);
            for (int i = 0; i < 10; i++)
            {
                if (carro[i].AnoFab == ano)
                {
                    printf("\nMarca: %s", carro[i].marca);
                    printf("\nModelo: %s", carro[i].modelo);
                    printf("\nAno: %d", carro[i].AnoFab);
                    printf("\nPlaca: %s", carro[i].placa);
                    printf("\n=================================== \n");
                    control++;
                }
                else
                {
                    if (control == 0)
                    {
                        printf("\nNao ha nenhum veiculo desse modelo registrado!");
                    }
                    break;
                }
            }
        }
        else if (x == 4)
        {
            int control2 = 0;
            int ano1 = 0;
            printf("\nDigite a partir de que ano dos veiculos deseja pesquisar no formato AAAA: ");
            scanf("%d", &ano1);
            for (int i = 0; i < 10; i++)
            {
                if (carro[i].AnoFab >= ano1)
                {
                    printf("\nMarca: %s", carro[i].marca);
                    printf("\nModelo: %s", carro[i].modelo);
                    printf("\nAno: %d", carro[i].AnoFab);
                    printf("\nPlaca: %s", carro[i].placa);
                    printf("\n===================================\n");
                    control2++;
                }
                else
                {
                    if (control2 == 0)
                    {
                        printf("\nNao ha nenhum veiculo acima desse ano registrado!");
                    }
                    break;
                }
            }
        }
        else if (x == 5)
        {
            int control3 = 0;
            char modelo[40] = "NOT";
            printf("\nDigite o modelo de veiculos que deseja pesquisar: ");
            scanf("%s", &modelo);
            for (int i = 0; i < 10; i++)
            {
                if (strcmp(modelo, carro[i].modelo) == 0)
                {
                    printf("\nMarca: %s", carro[i].marca);
                    printf("\nModelo: %s", carro[i].modelo);
                    printf("\nAno: %d", carro[i].AnoFab);
                    printf("\nPlaca: %s", carro[i].placa);
                    printf("\n===================================\n");
                    control3++;
                }
                else
                {
                    if (control3 == 0)
                    {
                        printf("\nNao ha nenhum veiculo desse modelo registrado!");
                    }
                    break;
                }
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
