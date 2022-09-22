#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//READ ME
// please check below
// setting edgeNum : for expressing the graph it is needed

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
        edgeNum = 0;
    }
    //Structures
    struct Vertix{
        int key;
        struct Vertix* v;
        struct Vertix* next;
    };
    //Global Variables
    int time;//used for timestanping
    int edgeNum;
    typedef struct Vertix* VertixPointer;
    struct Vertix verticies[MAX];//used as 1 origine 
    int color[MAX];//used for DFS : 1 origine
    int discover[MAX];//used for DFS : 1 origine
    int finished[MAX];//used for DFS : 1 origine
    map<int, bool> visited;//binary Tree like array
    VertixPointer targetLastNode;
    //Prototype Declarations
    void MakeGraphAsAdjacencyList(int n);//n edges Graph make
    void MakeNewEdge(VertixPointer u);
    void FindLastNode(VertixPointer v);
    void Display(VertixPointer v,int n); 
    void DFS();
    void DFS_VISIT(int u);
};
void MyGraph::MakeGraphAsAdjacencyList(int n)
{
    edgeNum = n;
    // making adjacent list
    for(int i = 1 ; i <= edgeNum ; i++)// 1 origine loop
    {
        int v;//target vertex
        scanf("%d", &v);
        verticies[v].next = verticies[v].v = nullptr;
        verticies[v].key = v;
        int k;//the degrees the target have
        scanf("%d", &k);
        FindLastNode(&verticies[v]);
        for(int j = 0 ; j < k ; j++)
        {
            int u;
            scanf("%d", &u);
            //search the last node of target vertex
            MakeNewEdge(&verticies[u]);
            targetLastNode = targetLastNode->next; //move to the next last node;
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
    for(VertixPointer tmp = verticies[u].next; tmp != NULL ; tmp = tmp->next)
    {
        if(color[tmp->v->key]==WHITE)
        {
            DFS_VISIT(tmp->v->key);//by Adjecent vertex,implement DFS_VISIT(key)
        }
    }
    color[u] = BLACK;
    time = time + 1;
    finished[u] = time;
}
void MyGraph::MakeNewEdge(VertixPointer u)
{
    VertixPointer tmp;
    tmp = (struct Vertix *)malloc(sizeof(struct Vertix));
    tmp->v = u;
    tmp->next = NULL;
    targetLastNode->next = tmp;
}
void MyGraph::FindLastNode(VertixPointer v)
{
    VertixPointer tmp;
    for(tmp = v; tmp->next != NULL ; tmp = tmp->next)cout <<"test"<<endl;;
    targetLastNode = tmp;
}
void MyGraph::Display(VertixPointer v,int n)
{
    for(int i = 1 ; i <= n; i++)
    {
        cout << i << " " << discover[i]<< " " << finished[i] << endl;
        // for(VertixPointer j = v[i].next; j!= NULL; j = j->next)
        // {
        //     cout << j->v->key << " ";
        // }
        // cout <<endl;
    }
}

int main()
{
    MyGraph g;
    int n;
    g.time = 0;
    scanf("%d",&n);
    g.MakeGraphAsAdjacencyList(n);
    //DFS implements
    g.DFS();
    g.Display(g.verticies,n);
    return 0;
}