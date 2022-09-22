#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 101
//Structure
//Prototype Declaration
void Dijkstra();
//Global Variables
int **g_mtrx;
int g_n;

int main()
{
    int t,dgr,u;
    int trgtVrtx,cst;
    scanf("%d",&g_n);
    //make matrix n*n
    g_mtrx = (int**)malloc(sizeof(int *) * g_n);
    for(int i = 0 ; i < g_n ; i++)
    {
        g_mtrx[i] = (int *)malloc(sizeof(int) * g_n);
        for(int j = 0 ;j < g_n; j++)
        {
            g_mtrx[i][j] = INT_MAX;
        }
    }

    //input the relationship
    //times and vertex
    for(int i = 0 ; i < g_n ; i++)
    {
        scanf("%d",&u);
        scanf("%d",&dgr);
        //times
        for(int j = 0; j < dgr;j++)
        {
            scanf("%d",&trgtVrtx);
            scanf("%d",&cst);
            g_mtrx[u][trgtVrtx] = cst;
            //printf("%d %d\n",trgtVrtx,cst);
        }
    }

    Dijkstra();
    return 0;
}

void Dijkstra()
{
    int minv;
    int d[N],color[N]; // 0 origine
    //initializing
    for(int i = 0; i< g_n ; i++)
    {
        d[i] = INT_MAX;
        color[i] = WHITE;
    }

    d[0] = 0;
    color[0] = GRAY;
    while(1)
    {
        minv = INT_MAX; //最小値を求めたいので、最大値を入れて初期化
        int u = -1;//探索予定ノードを存在しない数値で初期化
        for(int i = 0 ; i < g_n ; i++)
        {
            if(minv>d[i] && color[i] != BLACK)
            {
                u = i;
                minv = d[i];
            }
        }
        if(u == -1)break;
        color[u] = BLACK;
        for(int v = 0 ; v < g_n ; v++)
        {
            if(color[v] != BLACK && g_mtrx[u][v] != INT_MAX)//未探索かつ接続先がある場合
            {
                if(d[v] > d[u] + g_mtrx[u][v])//！IMPORTANT //
                {
                    d[v] = d[u] + g_mtrx[u][v];
                    color[v]=GRAY;
                }
            }
        }
    }
    for(int i = 0; i < g_n ; i++)
    {
        printf("%d %d\n",i,d[i]);
    }
}