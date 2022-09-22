#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
//Macros
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
//Structures
typedef struct Vrtx* VrtxPointer;
struct Vrtx{
    int key;
    VrtxPointer u;
    VrtxPointer next;
};
//Prototype Declarations
void BFS(struct Vrtx* G);
VrtxPointer MakeAdjList(struct Vrtx* G,int v,int u);
VrtxPointer MakeNewNode();
VrtxPointer FindLastNode(struct Vrtx G[],int v);
//Global Variables
int color[MAX];
int d[MAX] ={0};//detected time
int f[MAX] = {0};//finished time
int tm =0;//time calc
int numVerticies = 0;
int main()
{
    int n;
    scanf("%d",&n);
    struct Vrtx G[n+1];// 1 origine
    numVerticies = n;
    for(int i = 1 ; i <= n ; i++){G[i].next = G[i].u = nullptr;G[i].key = i;}
    
    int v,degree,u;
    for(int i = 1 ; i <= n ; i++)// 1 origine
    {
        scanf("%d%d",&v,&degree);
        for(int j = 0; j < degree ; j++)
        {
            scanf("%d",&u);
            //Make new pointer
            //Find the last Adjacency vertix in G[v]
            //connect new pointer to the above's vertex.next;
            MakeAdjList(G,v,u);
        }
    }
    BFS(G);
    for(int i = 1 ; i <= numVerticies ; i++)
    {
        if(d[i]== INT_MAX)cout << i << " " << -1 << endl;
        else cout << i << " " << d[i] << endl;
    }
    return 0;
}
void BFS(struct Vrtx* G)
{
    //initialize
    for(int i = 1 ; i <= numVerticies ; i++)
    {
        color[i] =WHITE;
        d[i] = INT_MAX;
    }
    int v = 1;
    if(color[v] == WHITE){
        color[v] = GRAY;
        queue<int> q;
        q.push(G[v].key);
        d[v] = 0;
        while(q.empty() != true)
        {
            int u = q.front();
            q.pop();
            for(VrtxPointer newv = G[u].next; newv ; newv = newv->next)
            {
                if(color[newv->u->key] == WHITE)
                {
                    color[newv->u->key] = GRAY;
                    q.push(newv->u->key);
                    d[newv->u->key] = d[u] + 1;
                }
            }
            color[u] = BLACK;
        }
    }

}
VrtxPointer MakeAdjList(struct Vrtx* G,int v,int u)
{
    VrtxPointer newNode = MakeNewNode();
    if(newNode == nullptr) return nullptr; // error
    newNode->next = nullptr;
    newNode->u = &G[u];
    VrtxPointer lastNodeOfGv = FindLastNode(G,v);
    if(lastNodeOfGv == nullptr) return nullptr; // error
    lastNodeOfGv->next = newNode;
    return newNode;
}

VrtxPointer MakeNewNode()
{
    return (VrtxPointer)malloc(sizeof(struct Vrtx));
}

VrtxPointer FindLastNode(struct Vrtx G[],int v)
{
    VrtxPointer i;
    for(i = &G[v] ; i->next ; i = i->next);
    return i;
}