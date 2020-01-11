#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "2048.h"

void mostrar (int grelha[][10], int sz)
{
    for (int r=0; r<sz; r++) //imprime a matriz
    {
        for (int t=0; t<sz; t++)
        {
            printf("%3d ", grelha[r][t]);
        }
        printf("\n");
    }

    printf("\n");
}

void fim_de_jogo(int grelha[][10], int sz, int numero_total_de_comb, char *token)
{
    int i, j;

    for(i=0; i<sz; i++)
    {
        for (j=0; j<sz; j++)
        {
            if (grelha[i][j]==2048)
            {
                printf("\nParabens, voce ganhou!\nO numero total de combinacoes durante o jogo foi:%d.\n", numero_total_de_comb);
                conta_pecas(grelha, sz);
                exit(1);
            }
        }


    }

        if(token==NULL)
        {printf("Game over.\n");
        printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
        conta_pecas(grelha, sz);
        exit(1);}

}

int main()
{

    int sz;
    int grelha[10][10];
    char input[2];
    int numero_de_comb = 0;
    int numero_total_de_comb = 0;
    char c;
    FILE *FICHEIRO;
    char texto_do_ficheiro[44];
    int i = 0;
    FICHEIRO = fopen("ficheiro.txt", "r");
    while((c = getc(FICHEIRO) ) != EOF)      /* Enquanto não chegar ao final do arquivo */
    {
        texto_do_ficheiro[i]=c;
        i++;
    }
    char aux[5];
    char *token;
    char delim1[3] = " \n";
    token = strtok(texto_do_ficheiro, delim1);
    strcpy(aux, token);
    sz = atoi(aux);

    for(int i = 0; i<sz; i++)
    {
        for (int j = 0; j<sz; j++)
        {
            token = strtok(NULL, delim1);
            strcpy(aux, token);
            grelha[i][j]=atoi(aux);
        }
    }

    strcpy(input, token);

    printf("Grelha inicial:\n\n");
    mostrar(grelha,sz);

    while(strcasecmp(input, "F")!=0)
    {


        token = strtok(NULL, delim1);
        if(token!=NULL)
        {strcpy(input, token);}
        else
            {
             fim_de_jogo(grelha, sz, numero_total_de_comb, token);
            }


        if(strcasecmp(input, "F")==0)
        {
            printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
            conta_pecas(grelha, sz);
            printf("A sair...");
            exit(1);
        }
        else
        {
            printf("Sentido: %s\n\n", input);
            numero_de_comb = jogada(grelha, sz, input);
            numero_total_de_comb = numero_total_de_comb + numero_de_comb;
            mostrar(grelha, sz);
            printf("Numero de combinacoes: %d\n\n", numero_de_comb);
            fim_de_jogo(grelha, sz, numero_total_de_comb, token);
        }
    }

    return 0;
}
