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
NodePointer Find(NodePointer,int );
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

    //this place of comment outs are about Find node but this section do not use those
    // if( (newnode = Find(key)) == NULL ){//if the key does not exist in the Tree, make node and insert
    //     newnode = MakeNode;
    //     newnode->key = key;// set the key
    // }else{//if the key exists, not do anything and return NULL
    //     return NULL;
    // }
    //if successing the insert, return the node
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
//Inorder()
void Inorder(NodePointer n){
    if(n == NULL){
        //finish requrements for recursive funstion 
    }else{
        Inorder(n->left);
        printf(" %d",n->key);
        Inorder(n->right);
    }
}
//Find()
NodePointer Find(NodePointer T , int key)
{
    while(T != NULL && key != T->key )
    {
        if(key < T->key){
            T = T->left;
        }else{
            T = T->right;
        }
    }
    return T;
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
        }else if(cmd[0] == 'p'){
            Inorder(root);
            printf("\n");
            Preorder(root);
            printf("\n");
        }else if(cmd[0] == 'f'){
            scanf("%d",&key);
            if(Find(root, key) !=NULL){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}