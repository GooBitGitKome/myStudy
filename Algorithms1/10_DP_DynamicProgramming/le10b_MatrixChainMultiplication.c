#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 101
//Structure
//Prototype Declaration
void MatrixChainMultiprication();
void MatrixChainMultiprication_1();
//Global Variables
int g_n;
int g_M[MAX][MAX];
int g_P[MAX];//matrix times(Ai-1,Ai)(行列掛け算）に必要な共通倍数部分の記録
int main()
{
    //initializing-----------------------------------------
    scanf("%d",&g_n);
    for(int i = 1 ; i <= g_n ; i++)
    {
        scanf("%d %d", &g_P[i-1], &g_P[i]);
        //printf("%d %d\n", g_P[i-1], g_P[i]);
    }
    //initializing-----------------------------------------
    MatrixChainMultiprication_1();
    printf("%d\n",g_M[0][g_n]);
    return 0;
}

void MatrixChainMultiprication()
{
    //initializing-----------------------------------------
    int j,min = 0;
    for(int i = 0; i < g_n ; i++)
    {
        g_M[i][i]= 0;
    }
    //initializing-----------------------------------------
    int t1,t2;
    for(int l = 2; l <= g_n ; l++)
    {
        for(int i = 1; i <= g_n - l + 1; i++)
        {
            j = i + l - 1;
            g_M[i][j] = INT_MAX;
            for(int k = i; k <= j ; k++)
            {
                t1 = g_M[i][j];
                t2 = g_M[i][k] + g_M[k+1][j] + g_P[i-1]* g_P[k] * g_P[j];
                //enter min
                g_M[i][j] = (t1 < t2) ? t1 : t2;
                //printf("%d\n",g_M[i][j] );
            }
        }
    }
}

void MatrixChainMultiprication_1()
{
    //initializing-----------------------------------------
    int j,min = 0;
    for(int i = 0; i < g_n ; i++)
    {
        g_M[i][i]= 0;
    }
    //initializing-----------------------------------------
    int t1,t2;
    for(int l = 2; l <= g_n ; l++)
    {
        for(int i = 1; i <= g_n - l + 1; i++)
        {
            j = i + l - 1;
            g_M[i][j] = INT_MAX;
            for(int k = i; k <= j ; k++)
            {
                t1 = g_M[i][j];
                t2 = g_M[i][k] + g_M[k+1][j] + g_P[i-1]* g_P[k] * g_P[j];
                //enter min
                g_M[i][j] = (t1 < t2) ? t1 : t2;
                //printf("%d\n",g_M[i][j] );
            }
        }
    }
}