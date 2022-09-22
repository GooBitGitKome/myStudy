#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODE 25
//Structure
struct Node{
    int id;
    int degrees;
    int depth;
    int height;
    struct Node* parent;
    struct Node* l_child;//left child
    struct Node* r_child;//right child
    struct Node* sibling;
};
typedef struct Node* NodePointer;
//Prototype Declaration
void Display(NodePointer);
void SetDepth(NodePointer);
int SetHeight(NodePointer);

//Global variables
int maxDepth = 0;

int main()
{
    //initializing-----------------------------------------
    int n;// the number of all nodes;
    int id,l_id,r_id;
    struct Node T[MAX_NODE];
    scanf("%d", &n);
    //NULL de initialize
    for(int i = 0 ; i < n ; i++){
        T[i].parent = T[i].l_child = T[i].r_child = T[i].sibling = NULL;
        T[i].degrees = T[i].depth =  0;
    }
    //initializing-----------------------------------------
    // input informatin of Binary Tree
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&id);
        T[id].id = id;
        //left child----------------------------
        scanf("%d",&l_id);
        if(l_id != -1){
            //setting child info to the child
            T[l_id].id = l_id;
            T[l_id].parent = &T[id];
            //set this child to the parent's left
            T[id].l_child = &T[l_id];
        }
        //right child----------------------------
        scanf("%d",&r_id);
        if(r_id != -1){
            //setting child info to the child
            T[r_id].id = r_id;
            T[r_id].parent = &T[id];
            //set this child to the parent's left
            T[id].r_child = &T[r_id];
        }      
        //setting siblings-----------------------
        if(l_id != -1 && r_id != -1){
            T[l_id].sibling = &T[r_id];
            T[r_id].sibling = &T[l_id];
        }
        //setting degree------------------------
        T[id].degrees += (l_id == -1)? 0 : 1;
        T[id].degrees += (r_id == -1)? 0 : 1;

    }
    // Set depth before the calc of height
    for(int i = 0 ; i < n ; i++)SetDepth(&T[i]);
    //Set height after setting depth
    for(int i = 0 ; i < n ; i++)T[i].height = SetHeight(&T[i]);
    //Display
    for(int i = 0 ; i < n ; i++)Display(&T[i]);
    
    return 0;
}

void Display(NodePointer T)
{
    printf("node %d: ",T->id);
    printf("parent = %d, ",(T->parent) == NULL? -1 : T->parent->id);
    printf("sibling = %d, ",T->sibling == NULL? -1 : T->sibling->id);
    printf("degree = %d, ",T->degrees);
    printf("depth = %d, ",T->depth);
    printf("height = %d, ",T->height);
    if(T->parent == NULL)printf("root");
    else if(T->degrees == 0)printf("leaf");
    else printf("internal node");
    printf("\n");       

}
void SetDepth(NodePointer T)
{
    int d = 0;
    NodePointer u = T;
    while(u->parent != NULL)
    {
        d++;
        u = u->parent;
    }
    //memolize the max depth, which is used to calculate the height: we take the deferences the max depth and the target object depth;
    if(maxDepth < d)maxDepth = d;
    //set the depth to T
    T->depth = d;
}

//recursive IMPORTANT!
int SetHeight(NodePointer T)
{
    int h1, h2;
    h1 = h2 = 0;
    if(T->l_child != NULL)h1 = SetHeight(T->l_child) + 1;
    if(T->r_child != NULL)h2 = SetHeight(T->r_child) + 1;
    return h1 > h2? h1 : h2;
}