#include <iostream>
using namespace std;
//Macros
#define MAX 101
//Structures
struct Vert{
    int key;
    struct Vert* v;
    struct Vert* next;
};
typedef struct Vert* VertPointer;
//Prototype Declarations
VertPointer MakeVert(VertPointer u);
VertPointer FindLastNode(VertPointer v);
void Display(VertPointer v,int n);

//Global Variables
int main()
{
    int n;
    struct Vert verticies[MAX];//used as 1 origine 
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)// 1 origine loop
    {
        int v;//target vertex
        scanf("%d", &v);
        verticies[v].next = verticies[v].v = NULL;
        verticies[v].key = v;
        int k;//the degrees the target have
        scanf("%d", &k);
        VertPointer targetLastNode = FindLastNode(&verticies[v]);
        for(int j = 0 ; j < k ; j++)
        {
            int u;
            scanf("%d", &u);
            //search the last node of target vertex
            targetLastNode->next = MakeVert(&verticies[u]);
            targetLastNode = targetLastNode->next; //move to the next last node;
        }
    }
    Display(verticies,n);

    return 0;
}

VertPointer MakeVert(VertPointer u)
{
    VertPointer tmp;
    tmp = (struct Vert *)malloc(sizeof(struct Vert));
    tmp->v = u;
    tmp->next = NULL;
    return tmp;
}

VertPointer FindLastNode(VertPointer v)
{
    VertPointer tmp;
    for(tmp = v; tmp->next != NULL ; tmp = tmp->next)cout <<"test"<<endl;;
    return tmp;
}

void Display(VertPointer v,int n)
{
    for(int i = 1 ; i <= n; i++)
    {
        for(VertPointer j = v[i].next; j!= NULL; j = j->next)
        {
            cout << j->v->key << " ";
        }
        cout <<endl;
    }
}