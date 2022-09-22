#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODE 26
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
void GetRoot(NodePointer);
void SetDepth(NodePointer);
int SetHeight(NodePointer);
//TreeWalk
void TreeWalkPreorder(NodePointer);
void TreeWalkInorder(NodePointer);
void TreeWalkPostorder(NodePointer);
//Global variables
int maxDepth = 0;
NodePointer g_root;

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
    GetRoot(T);
    //TreeWalk Display--------------
    printf("Preorder\n");
    TreeWalkPreorder(g_root);
    printf("\n");
    printf("Inorder\n");
    TreeWalkInorder(g_root);
    printf("\n");
    printf("Postorder\n");
    TreeWalkPostorder(g_root);
    printf("\n");
    return 0;
}

void GetRoot(NodePointer T)
{
    for(g_root = T; g_root->parent != NULL;g_root = g_root->parent); 
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


void TreeWalkPreorder(NodePointer T)
{
    if(T == NULL){
        //end requirement
    }else{
        printf(" %d", T->id);
        TreeWalkPreorder(T->l_child);
        TreeWalkPreorder(T->r_child);
    }
}

void TreeWalkInorder(NodePointer T)
{
    if(T == NULL){
        //end requirement
    }else{
        
        TreeWalkInorder(T->l_child);
        printf(" %d", T->id);
        TreeWalkInorder(T->r_child);
    }
}

void TreeWalkPostorder(NodePointer T)
{
    if(T == NULL){
        //end requirement
    }else{
        
        TreeWalkPostorder(T->l_child);
        TreeWalkPostorder(T->r_child);
        printf(" %d", T->id);
    }
}