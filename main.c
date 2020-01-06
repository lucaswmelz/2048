#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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
    int numerodecombinacoes = 0;
    int i, j, h;
    int count = 0;

    /* joga os numeros para a direita se houver posições livres (com 0's) */

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
            if(grelha[i][j]==grelha[i][j-1] && grelha[i][j]!=0)
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

int esquerda (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int i, j, h;
    int count = 0;

    /* joga os numeros para a esquerda se houver posições livres (com 0's) */

    for (i=0; i<sz; i++)
    {
        for(j=1; j<sz; j++)
        {
            if(grelha[i][j]!=0)
            {
                for(h=j-1; h>=0; h--)
                {
                    if(grelha[i][h]==0)
                    {
                        count++;
                    }
                }
                if(count>0)
                {
                    grelha[i][j-count]=grelha[i][j];
                    grelha[i][j]=0;
                }
            }
            count = 0;
        }
    }

    /* soma os numeros iguais */

    for (i=0; i<sz; i++)
    {
        for(j=0; j<sz-1; j++)
        {
            if(grelha[i][j]==grelha[i][j+1] && grelha[i][j]!=0)
            {
                grelha[i][j]=grelha[i][j]*2;
                grelha[i][j+1]=0;
                numerodecombinacoes++;
            }
            if(grelha[i][j]==0)
            {
                grelha[i][j]=grelha[i][j+1];
                grelha[i][j+1]=0;
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
            if(grelha[i][j]==grelha[i-1][j] && grelha[i][j]!=0)
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

int cima (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int count = 0;
    int i, j, h;

    for(i=1; i<sz; i++)
    {
        for (j=0; j<sz; j++)
        {
            if(grelha[i][j]!=0)
            {
                for(h=i-1; h>=0; h--)
                {
                    if(grelha[h][j]==0)
                    {
                        count++;
                    }
                }

                if (count>0)
                {
                    grelha[i-count][j]=grelha[i][j];
                    grelha[i][j]=0;
                }
            }
            count = 0;


        }
    }

    for (i=0; i<sz-1; i++)
    {
        for(j=0; j<sz; j++)
        {
            if(grelha[i][j]==grelha[i+1][j] && grelha[i][j]!=0)
            {
                grelha[i][j]=grelha[i][j]*2;
                grelha[i+1][j]=0;
                numerodecombinacoes++;
            }
            if(grelha[i][j]==0)
            {
                grelha[i][j]=grelha[i+1][j];
                grelha[i+1][j]=0;
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

void conta_pecas (int grelha[][10], int sz)
{
    int pecas[11];
    for(int i=0; i<11; i++)
    {
        pecas[i]=0;
    }

    for (int i = 0; i<sz; i++)
    {
        for (int j = 0; j<sz; j++)
        {
            if (grelha[i][j]<=64)
            {
                if(grelha[i][j]<=8)
                {
                    if(grelha[i][j]==2)
                    {
                        pecas[0]=pecas[0]+1;
                    }
                    else
                    {
                        if(grelha[i][j]==4)
                        {
                            pecas[1] = pecas[1]+1;
                        }
                        else
                        {
                            pecas[2]=pecas[2]+1;
                        }
                    }
                }

                else // se for menor ou igual a 64 e maior que 8
                {
                    if(grelha[i][j]==16)
                    {
                        pecas[3]=pecas[3]+1;
                    }
                    else
                    {
                        if(grelha[i][j]==32)
                        {
                            pecas[4]=pecas[4]+1;
                        }
                        else
                        {
                            pecas[5]=pecas[5]+1;
                        }
                    }
                }

            }
            else // se for maior do que 64
            {
                if(grelha[i][j]<=512)
                {
                    if(grelha[i][j]==128)
                    {
                        pecas[6]=pecas[6]+1;
                    }
                    else
                    {
                        if(grelha[i][j]==256)
                        {
                            pecas[7]=pecas[7]+1;
                        }
                        else
                        {
                            pecas[8]=pecas[8]+1;
                        }
                    }
                }
                else // se for 1024 ou 2048
                {
                    if(grelha[i][j]==1024)
                    {
                        pecas[9]=pecas[9]+1;
                    }
                    else
                    {
                        pecas[10]=pecas[10]+1;
                    }
                }

            }

        }
    }
for(int i=0; i<11;i++)
{
    if(pecas[i]!=0)
    {
        printf("Quantidade de pecas com o valor %d: %d.\n", (int)pow(2,(i+1)), pecas[i]);
    }
}

}
int jogada(int grelha[][10], int sz, char sentido[])
{
    int ncomb=0;
    if(strcasecmp(sentido, "B")==0)
    {
        ncomb = baixo(grelha, sz);
    }
    else if(strcasecmp(sentido, "C")==0)
    {
        ncomb = cima(grelha, sz);
    }
    else if(strcasecmp(sentido, "D")==0)
    {
        ncomb = direita(grelha, sz);
    }
    else if(strcasecmp(sentido, "E")==0)
    {
        ncomb = esquerda(grelha, sz);
    }
    return ncomb;
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

    mostrar(grelha, sz);

    while(strcasecmp(input, "F")!=0)
    {
        printf("Sentido(F para sair): ");
        scanf("%s", input);
        if(strcasecmp(input, "F")==0)
        {
            printf("A sair...");
            exit(1);
        }
        else
        {
            numero_de_comb = jogada(grelha, sz, input);
            numero_total_de_comb = numero_total_de_comb + numero_de_comb;
            novonumero(grelha,sz);
            mostrar(grelha, sz);
            printf("Numero de combinacoes: %d\n\n", numero_de_comb);
            fim_de_jogo(grelha,sz,numero_total_de_comb);
        }
    }

    return 0;
}
