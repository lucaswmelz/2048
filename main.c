#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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

int baixo (int grelha[][10], int sz)
{

    for (int i=sz; i>0; i--)
    {
        for(int j=0; j<sz; j++)
        {
            if (grelha[i][j]==grelha[i-1][j])
            {
                grelha[i][j]=grelha[i][j]*2;
                if(i-2<0)
                {
                    grelha[i-1][j]=0;
                }
                else
                    grelha[i-1][j]=grelha[i-2][j];
            }
        }
    }
}


int main()
{
    int sz;
    printf("Qual a dimensao da grelha?\n");
    scanf("%d", &sz);
    srand(time(NULL));
    int grelha[sz][sz];

    //inicializando a grelha
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
        int linha1 = rand()%sz;
        int coluna1 = rand()%sz;
    }
    grelha[linha1][coluna1] = geranumero();
    // termina de inicializar a grelha



    for (int r=0; r<sz; r++) //imprime a matriz
    {
        for (int t=0; t<sz; t++)
        {
            printf("%2d", grelha[r][t]);
        }
        printf("\n");
    }

}
