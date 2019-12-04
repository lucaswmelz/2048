#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int baixo (int grelha[][], int sz)
{

for (i=sz;i>0;i--):
    {
     for(j=0;j<sz;j++)
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


int geranumero()
{
int a = rand()%3;
    if(a<2)
    {
        return 2;
    }
    else
        return 4;
}

int main()
{
int sz;
printf("Qual a dimensao da grelha?\n");
scanf("%d", &sz);
srand(time(NULL));
int grelha[sz][sz];
for(int i=0; i<sz; i++)
{
    for(int j=0; j<sz; j++)
    {
        grelha[i][j]=geranumero();
    }

}

for (int r=0; r<sz; r++)
{
    for (int t=0; t<sz; t++)
    {
        printf("%2d ", grelha[r][t]);
    }
    printf("\n");
}

}
