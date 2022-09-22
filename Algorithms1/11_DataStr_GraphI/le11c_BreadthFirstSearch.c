#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N  101
#define WHITE 0
#define GRAY 1
#define BLACK 2
//Structure
//Prototype Declaration
void Bfs();
void Enqueue(int u);
int Dequeue();
int isEmpty();
int isFull();
//Global Variables
int n,u;
int G[N][N];
int C[N],d[N];
int *Queue;
int q_tail = 1;
int q_head = 1;

int main()
{
    int degree,buff,v;
    scanf("%d",&n);
    //initialize Queue array
    Queue = (int * )malloc(sizeof(int) * n +1);
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
    Bfs();

    for(int i = 1 ; i <= n ; i++)
    {

        printf("%d %d", i, d[i]);
        printf("\n");
    }
    

    return 0;
}

void Bfs()
{
    //path flag: if it is 0 , it means to be away from main path 1 to u;
    int p_flg =0;
    //initialize
    for(int i = 0 ; i <= n ; i++)
    {
        C[i] = WHITE;//ノード訪問をWHITEで初期化
        d[i] = INT_MAX;     
    }
    
    //start seaching
    C[1] = GRAY;
    d[1] = 0;
    Enqueue(1);
    while(isEmpty() != 0)
    {
        u = Dequeue();
        p_flg = 0;
        //n times loop vertex 1 to vertex n
        for(int v = 1 ; v <= n ;v++)
        {
            if(G[u][v] == 1 && C[v] == WHITE)
            {
                C[v] = GRAY;
                d[v] = d[u] + 1;
                Enqueue(v);
            }
        }
        C[u] = BLACK;
    }
    //最短経路のものを幅-1に設定
    for(int v = 1 ; v <= n ;v++)
    {
        if(d[v] == INT_MAX)d[v] = -1;
    }
}

void Enqueue(int u)
{
    if(isFull() == 0 ){
        Queue[q_tail] = u;
        //full flag
        Queue[N]++;
        q_tail = (q_tail + 1) % (n+1);
    }
}

int Dequeue()
{
    int getVal  = Queue[q_head];
    q_head = (q_head+1) % (n+1);
    //full flag
    Queue[N]--;
    return getVal;
}

int isEmpty()
{
    return Queue[N];
}

int isFull()
{
    if(Queue[N] != 0 && (q_tail == q_head))
    {
        //full
        return 1;
    }
    //not full
    return 0;
}