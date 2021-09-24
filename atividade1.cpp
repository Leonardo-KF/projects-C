#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct
    {
        char marca[40];
        char modelo[40];
        int AnoFab;
        char placa[8];
    } carros; //definicao da struct
    carros carro[10];
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
        printf("4 - Listar os veiculos apartir do ano de fabricacao de sua preferencia.\n");
        printf("5 - Listar os veiculos do modelo desejado. \n");
        printf("=============================================");
        printf("\nPor favor digite a opcao desejada: ");
        scanf("%d", &x);
        if (x == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                if (strcmp("NULL", carro[i].marca) == 0)
                {
                    printf("Nenhum veiculo registrado\n");
                    break;
                }
                printf("\nA marca do veiculo: %s", carro[i].marca);
                printf("\nO modelo do veiculo: %s", carro[i].modelo);
                printf("\nO ano do veiculo: %d", carro[i].AnoFab);
                printf("\nA placa do veiculo: %s", carro[i].placa);
            }
        }
        else if (x == 2)
        {
            printf("Digite a marca do veiculo: ");
            scanf("%s%*c", carro[indice].marca);
            printf("Digite o modelo do veiculo: ");
            scanf("%s%*c", carro[indice].modelo);
            printf("Digite o ano de fabricacao do veiculo: ");
            scanf("%d", &carro[indice].AnoFab);
            printf("Digite a placa do veiculo no formato XXX-YYYY: ");
            scanf("%s%*c", carro[indice].placa);
            indice++;
        }
        else if (x == 3)
        {
            int compara(carros * a, carros * b)
            {
                if (a->AnoFab == b->AnoFab)
                {
                    return 0;
                }
                else if (a->AnoFab > b->AnoFab)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
}