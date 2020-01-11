#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "2048.h"

int geranumero()
{
    int a = rand()%4;
    if(a<2)
    {
        return 2;
    }
    else
        return 4;
}

void inicializagrelha(int grelha[][10], int sz)
{
    int linha0 = rand()%sz;
    int coluna0 = rand()%sz;
    for (int r=0; r<sz; r++) // preenche a matriz com 0's
    {
        for (int t=0; t<sz; t++)
        {
            grelha[r][t]=0;
        }

    }

    grelha[linha0][coluna0] = geranumero();

    int linha1 = rand()%sz;
    int coluna1 = rand()%sz;
    while (linha0==linha1 && coluna0==coluna1)
    {
        linha1 = rand()%sz;
        coluna1 = rand()%sz;
    }
    grelha[linha1][coluna1] = geranumero();
}

void novonumero(int grelha[][10], int sz)
{
    int linha = rand()%sz;
    int coluna = rand()%sz;

    while (grelha[linha][coluna]!=0)
    {
        linha=rand()%sz;
        coluna=rand()%sz;
    }
    grelha[linha][coluna]= geranumero();
}

void fim_de_jogo(int grelha[][10], int sz, int numero_total_de_comb)
{
    int i, j;
    int controle1 = 0;
    int controle2 = 0;

    for(i=0; i<sz; i++)
    {
        for (j=0; j<sz; j++)
        {
            if (grelha[i][j]==2048)
            {
                printf("\nParabens, voce ganhou!\nO numero total de combinacoes durante o jogo foi:%d.", numero_total_de_comb);
                conta_pecas(grelha, sz);
                exit(1);
            }

            if(grelha[i][j]!=0)
            {
                controle1++;
            }
            if(grelha[i][j]!=grelha[i+1][j] && grelha[i][j]!=grelha[i-1][j] && grelha[i][j]!=grelha[i][j-1] && grelha[i][j]!=grelha[i][j+1])
            {
                controle2++;
            }
        }


    }

    if (controle1==(sz*sz)&&controle2==(sz*sz))
    {
        printf("Game over.\n");
        printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
        conta_pecas(grelha, sz);
        exit(1);
    }

}

int main()
{
    int sz;
    printf("Qual a dimensao da grelha? ");
    scanf("%d", &sz);
    srand(time(NULL));
    int grelha[10][10];
    inicializagrelha(grelha, sz);
    char input[2];
    int numero_de_comb = 0;
    int numero_total_de_comb = 0;

    //mostrar(grelha, sz);

    while(strcasecmp(input, "F")!=0)
    {
        printf("Sentido(F para sair): ");
        scanf("%s", input);
        if(strcasecmp(input, "F")==0)
        {
			printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
			conta_pecas(grelha, sz);
            printf("A sair...");
            exit(1);
        }
        else
        {
            numero_de_comb = jogada(grelha, sz, input);
            numero_total_de_comb = numero_total_de_comb + numero_de_comb;
            novonumero(grelha,sz);
            //mostrar(grelha, sz);
            printf("Numero de combinacoes: %d\n\n", numero_de_comb);
            fim_de_jogo(grelha,sz,numero_total_de_comb);
        }
    }

    return 0;
}
