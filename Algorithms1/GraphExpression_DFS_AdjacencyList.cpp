#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//READ ME
// please check below
// setting edgeNum : for expressing the graph it is needed
// use the array G being placed gloval variables

//Macros
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
//Graph
class MyGraph{
    public:
    MyGraph()
    {
        time = 0;
        edgeNum = 0;
    }
    //Structures
    struct Vertix{
        int key;
		int id;
        struct Vertix* p;//parent vertix
        struct Vertix* u;//the place having the key : original pointer
        struct Vertix* next;//next adjacency node
    };
    //Global Variables
    int time;//used for timestanping
    int edgeNum;
    typedef struct Vertix* VertixPointer;
    struct Vertix G[MAX];//used as 1 origine 
    int color[MAX];//used for DFS : 1 origine
    int discover[MAX];//used for DFS : 1 origine
    int finished[MAX];//used for DFS : 1 origine
    map<int, bool> visited;//binary Tree like array
    //Prototype Declarations
    void MakeGraphAsAdjacencyList(int n);//n edges Graph make
    VertixPointer MakeNewEdge(VertixPointer u);
    VertixPointer FindLastNode(VertixPointer v);
    void Display(VertixPointer v,int n); 
    void DFS();
    void DFS_VISIT(int u);
};
void MyGraph::MakeGraphAsAdjacencyList(int n)
{
    edgeNum = n;
    VertixPointer lastNode;
    // making adjacent list
    for(int i = 1 ; i <= edgeNum ; i++)// 1 origine loop
    {
        int v;//target vertex
        scanf("%d", &v);
        G[v].next = G[v].p = nullptr;
        G[v].key = v;
        G[v].id = v;
        int k;//the degrees the target have
        scanf("%d", &k);//the number of degree
        lastNode = FindLastNode(&G[v]);
        for(int j = 0 ; j < k ; j++)
        {
            int u;
            scanf("%d", &u);
            //search the last node of target vertex
            VertixPointer newNode= MakeNewEdge(&G[v]);
            newNode->id = u;
            newNode->key = u;
            newNode->u = &G[u];
            lastNode->next = newNode;
            lastNode = newNode;//next last node of v
        }
    }
}
void MyGraph::DFS()
{
    for(int i = 1; i <= edgeNum; i++)//1 origine
    {
        color[i] = WHITE;//initialize as WHITE color
    }
    // This loop is for some dependent node
    // If there is nothing, This loop finish once
    for(int u = 1; u <= edgeNum; u++)
    {
        if(color[u] ==WHITE)
        {
            DFS_VISIT(u);
        }
    }
}
void MyGraph::DFS_VISIT(int u)
{
    time = time + 1;
    discover[u] = time;//timestamping
    color[u] = GRAY;//chenge color
    for(VertixPointer tmp = G[u].next; tmp != nullptr ; tmp = tmp->next)
    {
        if(color[tmp->id]==WHITE)
        {
            DFS_VISIT(tmp->id);//using Adjecent vertex,implement DFS_VISIT(key)
        }
    }
    color[u] = BLACK;
    time = time + 1;
    finished[u] = time;
}
MyGraph::VertixPointer MyGraph::MakeNewEdge(VertixPointer u)
{
    VertixPointer tmp;
    tmp = (struct Vertix *)malloc(sizeof(struct Vertix));
    tmp->p = u;
    tmp->next = nullptr;
    return tmp;
}
MyGraph::VertixPointer MyGraph::FindLastNode(VertixPointer v)
{
    VertixPointer tmp;
    for(tmp = v; tmp->next != NULL ; tmp = tmp->next);
	return tmp;
}
void MyGraph::Display(VertixPointer v,int n)
{
    for(int i = 1 ; i <= n; i++)
    {
        //check the discover and finished time
        cout << i << " " << discover[i]<< " " << finished[i] << endl;
        //check the adjacency lists
        // cout << i <<":";
        // for(VertixPointer j = G[i].next; j != nullptr ; j = j->next)
        // {
        //     cout << " " <<j->key;
        // }
        // cout << endl;
    }
}

int main()
{
    MyGraph g;
    int n;
    scanf("%d",&n);
    g.MakeGraphAsAdjacencyList(n);
    //DFS implements
    g.DFS();
    g.Display(g.G,n);
    return 0;
}