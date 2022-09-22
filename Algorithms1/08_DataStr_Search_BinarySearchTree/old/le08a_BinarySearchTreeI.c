#include <stdio.h>
#include <stdlib.h>

//Data Structure
struct node{
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
};
typedef struct node* NodePointer;
//Declaration of Prototype
NodePointer Insert(NodePointer ,int );
NodePointer Find(int );
NodePointer MakeNode();
void Inorder();
void Preorder();
void Postorder();
//Declaration of Variables  
NodePointer root;



//main Program
NodePointer Insert(NodePointer T ,int key)
{
    NodePointer newnode = MakeNode();
    newnode->key = key;
    NodePointer p = NULL;//x's parent
    NodePointer x = T;//current root at the frist as the top of root
    //search the parent for the node having the key
    while(x != NULL)
    {
        p = x; // set the parent
        if(newnode->key < x->key){
            x = x->left; // move to the left child
        }else{
            x = x->right; //move to the right child
        }
    }
    newnode->parent = p;
    
    //if the tree have no node, make the first root node
    if(T == NULL){
        root = newnode;
    }else if(newnode->key < p->key){// choose the left or right besed on whether the newnode.key is greater than the key of parent of newnode 
        //if newnode key is less than that of newnode parent
        p->left = newnode;
    }else{
        //if it is opposite
        p->right = newnode;
    }

    return newnode;
}
//MakeNode()
NodePointer MakeNode(){return malloc(sizeof(struct node));}
//preorder()
void Preorder(NodePointer n){
    if(n == NULL){
        //finish requrements for recursive funstion 
    }else{
        printf(" %d",n->key);
        Preorder(n->left);
        Preorder(n->right);
    }
}
void Inorder(NodePointer n){
    if(n == NULL){
        //finish requrements for recursive funstion 
    }else{
        Inorder(n->left);
        printf(" %d",n->key);
        Inorder(n->right);
    }
}
int main()
{
    int m = 0;//the number of operation
    int number;
    char cmd[6];//get the input of command
    int key = 0;
    NodePointer tmp;

    scanf("%d", &m);
    number = m;
    for(int i = 0; i < m ; i++)
    {
        scanf("%s",cmd);
        if(cmd[0] == 'i'){
            scanf("%d",&key);
            tmp = Insert(root, key);
        }else{
            Inorder(root);
            printf("\n");
            Preorder(root);
            printf("\n");
        }
    }
    return 0;
}