#include <stdio.h>
#include <stdlib.h>
#define N  101
#define WHITE 0
#define GRAY 1
#define BLACK 2
//Structure
//Prototype Declaration
void Dfs();
void DfsVisit(int);
int Next(int u);
void Push(int u);
int Pop();
//Global Variables
int n;
int G[N][N];
int C[N],d[N],f[N],nt[N];
int *Stack;
int top = 0;
int tt = 0;

int main()
{
    int degree,buff,v;
    scanf("%d",&n);
    //initialize stack array
    Stack = (int * )malloc(sizeof(int) * n +1);
    //create matrix G
    // input n lines
    for(int i = 0 ; i < n ; i++)
    {
        //input the vertex
        scanf("%d",&v);
        //input degree and loop based on the degree
        scanf("%d",&degree);
        for(int j = 0 ; j < degree ; j++)
        {
            //make the relation ship each node havs
            scanf("%d",&buff);
            G[v][buff] = 1;
        }
    }

    //DeepFirstSearching
    Dfs();

    for(int i = 1 ; i <= n ; i++)
    {

        printf("%d %d %d", i, d[i], f[i]);
        printf("\n");
    }
    

    return 0;
}

void Dfs()
{
    //initialize
    for(int i = 0 ; i < n ; i++)
    {
        C[i] = WHITE;//ノード訪問をWHITEで初期化
        nt[i] = 0;        
    }
    tt = 0;

    //未訪問のuを始点として深さ優先探索
    for(int u = 1; u <= n; u++)// 1 origine
    {
        //なぜ全て探索するかは、全てのノードが接続されていない場合を考慮してLinierチェックする
        if(C[u] == WHITE)DfsVisit(u);
    }
}

//Stackを用いたDFS
void DfsVisit(int u )
{
    //initializing
    for(int i = 0 ; i < n ; i++ ) nt[i] = 0;
    Push(u);//探索用Stackに現在参照中のNodeを追加する
    C[u] = GRAY;//チェック済みのVertex ｕに対して訪問済みとしてGrayカラーにする
    d[u] = ++tt;//Discovered time stump　
    //Stackのデータ数（探索中ノード数）が存在している間探索を続ける
    while(top != 0)
    {
        int u = Stack[top-1];//トップノード参照
        int v = Next(u);//トップノードに関連づけられている未訪問ノードを取得：-1の場合は次のノードが存在しない
        if( v != -1)
        {
            if(C[v] == WHITE)
            {
                C[v] = GRAY;
                d[v] = ++tt;
                Push(v); 
            }
        }else{//there is no next node
            Pop();
            C[u] = BLACK;
            f[u] = ++tt;
        }
    }
}
int Next(int u)
{
    //ここは教科書参照して作成したが、nt[]が何で何をしたいのかチェック
    for(int v = nt[u] ; v <= n ; v++)
    {
        //おそらくすでに見ているVertexを飛ばしてその後のVertexを参照する。さらに小さい順に参照していくようになっている
        nt[u] = v+1;//What is this?
        if(G[u][v])return v;//uに所属するVertexがあれば、その頂点を返す
    }
    //when the next node is none;
    return -1;
}

void Push(int u)
{
    Stack[top] = u;
    top++;
}

int Pop()
{
    top--;
    int tmp_Get  = Stack[top];
    return tmp_Get;
}