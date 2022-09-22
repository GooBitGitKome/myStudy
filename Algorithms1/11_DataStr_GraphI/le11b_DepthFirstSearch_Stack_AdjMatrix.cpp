#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Macros
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
//Structures
//Prototype Declarations
void Visit(int r);
void DFS();
int NextAdjacenct(int u);
//Global Variables
int M[MAX][MAX] = {0};// 1 origine 
int color[MAX] = {0};
//Timestanp[n][0]:discovered time 
//Timestanp[n][1]:finished time 
int Timestamp[MAX][2] = {0,0};
int N;//the number of array
int tim = 0;//for use of timestamp
int main()
{
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i++)//1 origine loop 
    {
        int l,u,v;
        scanf("%d%d", &u,&l);
        for(int j = 0 ; j < l ; j++)
        {
            scanf("%d",&v);
            M[u][v] = 1;
            //cout << v << " ";
        }
        //cout <<endl;
    }
    DFS();
    for(int i = 1 ; i <= N ; i++)
    {
        cout << i << " " << Timestamp[i][0] << " " <<Timestamp[i][1] << endl;
    }
    return 0;
}

void DFS()
{
    //initialize
    for(int i = 1 ; i <= N; i++)
    {
        color[i] = WHITE;
    }
    for(int u = 1 ; u <= N ; u++)
    {
        if(color[u] == WHITE)
        {
            Visit(u);
        }
    }
}
void Visit(int r)
{
    stack<int> s;
    Timestamp[r][0] = ++tim;
    color[r] = GRAY;
    s.push(r);//initial value
    int u;//current vertex
    int v;//adj vertex
    while(s.empty() != true)
    {
        u = s.top();
        v = NextAdjacenct(u);
        if(v > 0)//if there is Adjacency node 
        {
            if(color[v] == WHITE)
            {
                s.push(v);
                color[v] =GRAY;
                Timestamp[v][0]=++tim;
            }
        }else{//not
            s.pop();
            color[u] = BLACK;
            Timestamp[u][1] = ++tim;
        }
    }
}
int NextAdjacenct(int u)
{
    for(int i = 1 ; i <= N ; i++)
    {
        if(M[u][i] == 1)
        {
            M[u][i] = 0;
            return i;
        }
    }
     return 0;// minus is no adj
}