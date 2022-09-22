#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 101
//Structure
//Prototype Declaration
int Prim();
//Global Variables
int **matrix;
int n;

int main()
{
    int t;
    scanf("%d",&n);
    //make matrix n*n
    matrix = (int**)malloc(sizeof(int *) * n+1);
    for(int i = 1 ; i <= n ; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n+1);
    }

    //input the relationship
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j<=n;j++)
        {
            scanf("%d",&t);
            if(t == -1)matrix[i][j] = INT_MAX;
            else matrix[i][j] = t;
        }
    }
    Prim();
    return 0;
}

int Prim()
{
    //initializing
    int d[N],color[N],p[N];//1 origine
    // dを新たに作成する自由木とする// 1 origine
    int mincost;
    int u;
    int sum = 0;
    for(int i = 0 ; i < N ; i++)
    {
        d[i] = INT_MAX;//最大値で初期化
        p[i] = -1;
        color[i] = WHITE;
    }
    //-------------

    d[1]=0;//1 をRootとして自由木の作成に入る
    color[1] = GRAY;
    while(1)
    {
        mincost = INT_MAX;
        u = -1;//next node
        for(int i = 1 ; i <= n ; i++)
        {
            if(color[i] != BLACK && d[i] < mincost)//未探索ノードでINT_MAXでしょきかされたものではない場合（まだ未探索がある時）
            {
                mincost = d[i];//未探索かつ、最小ノード（次に行く予定のノード）
                u = i;//次に行く予定のノードを記憶
            }
        }
        if(u == -1)break;//全ノードが探索済み
        if(mincost == INT_MAX)break;//次に観に行くノードが存在しない時
        color[u] = BLACK;//uを訪問済みノードにする
        for(int v = 1 ; v <= n ; v++)//uに接続されている全ノード探索チェック
        {
            if(color[v]!=BLACK && matrix[u][v] != INT_MAX)//ノードが未探索かつ、そのノードに接続があるとき
            {
                //detect the minimum node in the adjacency verticies
                if(matrix[u][v] < d[v])//ループの初めは必ずTrueとなる。
                {
                    d[v] = matrix[u][v];//ここでuから出ているノード群から最小のノードと、そこへのコストを記録
                    p[v] = u;//vの親をuとして設定
                    color[v] = GRAY;//探索中のuに接続されているもの全て候補地としてGRAYに設定
                }
            }
        }
        sum = 0;
        for(int i = 1; i <= n ; i++)//再帰でも実現できそう。探索ノードの親からiへのコストの合計を計算
        {
            if(p[i] != -1)sum += matrix[i][p[i]];
        }
    }
    printf("%d\n",sum );
    return 0;
}