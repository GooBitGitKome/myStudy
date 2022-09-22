#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Structure
struct Node{
    int key;
    struct Node* parent;
    struct Node* left_child;//able to go down in the subtree;
    struct Node* right_sibling;
};
//Prototype Declaration
void GetSiblings(struct Node* u);
int GetDepth(struct Node *u);
//Global Variables
int main()
{
    //initializing-----------------------------------------
    int n;
    struct Node T[100001];//use the index 1 to 100000
    scanf("%d",&n);
    //IMPORTANT!!!!!!!!!!!
    for(int i = 0;i < n;i++)T[i].left_child = T[i].parent = T[i].right_sibling = NULL;
    //initializing-----------------------------------------
    //make tree-----------------------
    int id,degrees,sib_id;
    struct Node *prev_sibling;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d %d",&id,&degrees);
        T[id].key = id;
        //if this node have no siblings, it means external node;
        if(degrees == 0){//do nothing
        }else{
            //when there are siblings, set the relasionship and set the parent of each sibling
            for(int j = 0 ; j < degrees ; j++)
            {
                scanf("%d",&sib_id);
                //set the left child to the first sibling
                T[sib_id].parent = &T[id];//set the child' parent
                T[sib_id].key = sib_id;//set the key of sibling in the sibling . key
                if(j == 0){
                    T[id].left_child = &T[sib_id];//set info to parent //set the child
                    prev_sibling = T[id].left_child;
                }else{
                    //子供を左側から右へたどっていって、既存のシブリングの一番最後に追加する
                    // for( = T[id].left_child; tmp->right_sibling !=NULL ;tmp = tmp->right_sibling);
                    prev_sibling->right_sibling = &T[sib_id]; 
                    prev_sibling = prev_sibling->right_sibling;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("node %d: ",i);
        GetSiblings(&T[i]);
    }    
    return 0;
}

int GetDepth(struct Node *u)
{
    int d = 0;
    while(u->parent != NULL)
    {
        d++;
        u = u->parent;
    }
    return d;
}

void GetSiblings(struct Node* u)
{
    if(u->parent == NULL){
        printf("parent = -1, depth = 0, root, [");
    }else if(u->left_child == NULL){
        printf("parent = %d, depth = %d, leaf, [",u->parent->key, GetDepth(u));
    }else{
        printf("parent = %d, depth = %d, internal node, [",u->parent->key, GetDepth(u));
    }
    //uの子供の情報を知りたいので、uを一階層さげて、シブリングのチェック
    u = u->left_child;
    while(u != NULL)
    {
        printf("%d",u->key);
        u = u->right_sibling;
        if(u != NULL)printf(", ");
    }
    printf("]\n");
}