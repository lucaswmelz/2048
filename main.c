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

int direita (int grelha[][10], int sz)
{
    int numerodecombinacoes;
    int i, j, h;
    int count = 0;

    /* joga os numeros para a direita se houver posi��es livres (com 0's) */

    for (i=0; i<sz; i++)
    {
        for(j=sz-2; j>=0; j--)
        {
            if(grelha[i][j]!=0)
            {
                for(h=j+1; h<sz; h++)
                {
                    if(grelha[i][h]==0)
                    {
                        count++;
                    }
                }
                if(count>0)
                {
                    grelha[i][j+count]=grelha[i][j];
                    grelha[i][j]=0;
                }
            }
            count = 0;
        }
    }

    /* soma os numeros iguais */

    for (i=0; i<sz; i++)
    {
        for(j=sz-1; j>0; j--)
        {
            if(grelha[i][j]==grelha[i][j-1])
            {
                grelha[i][j]=grelha[i][j]*2;
                grelha[i][j-1]=0;
                numerodecombinacoes++;
            }
            if(grelha[i][j]==0)
            {
                grelha[i][j]=grelha[i][j-1];
                grelha[i][j-1]=0;
            }

        }
    }


    return numerodecombinacoes;
}


int baixo (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int count = 0;
    int i, j, h;

    for(i=sz-2; i>=0; i--)
    {
        for (j=0; j<sz; j++)
        {
            if(grelha[i][j]!=0)
            {
                for(h=i+1; h<sz; h++)
                {
                    if(grelha[h][j]==0)
                    {
                        count++;
                    }
                }

                if (count>0)
                {
                    grelha[i+count][j]=grelha[i][j];
                    grelha[i][j]=0;
                }
            }
            count = 0;


        }
    }

    for (i=sz-1; i>0; i--)
    {
        for(j=0; j<sz; j++)
        {
            if(grelha[i][j]==grelha[i-1][j])
            {
                grelha[i][j]=grelha[i][j]*2;
                grelha[i-1][j]=0;
                numerodecombinacoes++;
            }
            if(grelha[i][j]==0)
            {
                grelha[i][j]=grelha[i-1][j];
                grelha[i-1][j]=0;
            }

        }
    }

    return numerodecombinacoes;
}

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

void novonumero(int grelha[][10], int sz)
{
    int linha = rand()%sz;
    int coluna = rand()%sz;

    while (grelha[linha][coluna]!=0)
    {
        linha=rand()%sz;
        coluna=rand()%sz;
    }
    grelha[linha][coluna]=geranumero();
}

int main()
{
    int sz;
    printf("Qual a dimensao da grelha?\n");
    scanf("%d", &sz);
    srand(time(NULL));
    int grelha[10][10];
    inicializagrelha(grelha, sz);
    int testa=1;

    while(testa==1)
    {
        scanf("%d", &testa);
        printf("baixo\n");
        baixo(grelha, sz);
        mostrar(grelha, sz);
        printf("novo numero\n");
        novonumero(grelha, sz);
        mostrar(grelha, sz);
        printf("direita\n");
        direita(grelha,sz);
        mostrar(grelha, sz);
    }


    return 0;
}
