#include <stdio.h>
#include <stdlib.h>
//Data Structure
struct Node{
    int id;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};
typedef struct Node* NodePointer;
//Declaration of Prototype
NodePointer Insert(NodePointer ,int);
NodePointer Find(NodePointer , int );
void Display();
void Inorder(NodePointer);
void Preorder(NodePointer);
void Postorder(NodePointer);
NodePointer GetSuccessor(NodePointer z);
NodePointer Delete(NodePointer T, NodePointer z);
//Declaration of Variables  
NodePointer g_root;
int main()
{
    //initializing-----------------------------------------
    int n;//the number of operation
    int id;
    char cmd[10];//get the input of command
    //initializing-----------------------------------------
    scanf("%d", &n);
    for(int i = 0; i < n ; i++)
    {
        scanf("%s",cmd);
        if(cmd[0] == 'i'){//Insert
            scanf("%d",&id);
            Insert(g_root, id);
        }else if(cmd[0] == 'p'){//Display
            Display();
        }else if(cmd[0] == 'f'){
            scanf("%d",&id);
            if(Find(g_root,id) !=NULL){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(cmd[0] == 'd'){
            scanf("%d",&id);
            Delete(g_root,Find(g_root,id));
        }
    }
    return 0;
}

//main Program
NodePointer Insert(NodePointer T ,int id)
{
    NodePointer newnode =  malloc(sizeof(struct Node));
    newnode->id = id;
    //IMPORTANT初期化は絶対すること
    newnode->left = newnode->right = NULL;
    NodePointer p = NULL;//x's parent
    NodePointer x = g_root;//current root at the frist as the top of root

    //search the parent for the node having the id
    while(x != NULL)
    {
        //p is the prev node of x;it means x's parent
        p = x; // set the parent
        if(newnode->id < x->id){
            x = x->left; // move to the left child
        }else{
            x = x->right; //move to the right child
        }
    }
    newnode->parent = p;
    
    if(T == NULL){//if the tree have no node, make the g_root node
        g_root = newnode;
    }else if(newnode->id < p->id){// choose the left or right besed on whether the newnode.id is greater than the id of parent of newnode 
        //if newnode id is less than that of newnode parent
        p->left = newnode;
    }else{
        //if it is opposite
        p->right = newnode;
    }

    return newnode;
}
//Display
void Display()
{
    Inorder(g_root);
    printf("\n");
    Preorder(g_root);
    printf("\n");
}
//preorder()
void Preorder(NodePointer r){
    if(r == NULL){
        //finish requrements for recursive funstion 
    }else{
        printf(" %d",r->id);
        Preorder(r->left);
        Preorder(r->right);
    }
}
//Inorder 巡回
void Inorder(NodePointer r){
    if(r == NULL){
        //finish requrements for recursive funstion 
    }else{
        Inorder(r->left);
        printf(" %d",r->id);
        Inorder(r->right);
    }
}

//Find
NodePointer Find(NodePointer T , int id)
{
    while(T != NULL && id != T->id)
    {
        if(id < T->id){
            T = T->left;
        }else{
            T = T->right;
        }
    }
    return T;
}

//DeleteNode
NodePointer Delete(NodePointer T, NodePointer z)
{
    NodePointer y = NULL;//削除対象接点を　y　とする
    NodePointer x = NULL;//削除対象接点を　y　のこどもを　ｘ　とする
    //削除候補ノードzが両サイドまたは片方子供を持たない時
    if(z->left == NULL || z->right ==NULL)
    {
        //片方・または両方の子供がない時の処理-----------------------
        y = z;
        //y の子供 x を決める: 右側優先
        if(y->left != NULL)
        {
            x = y->left;
        }else{
            x = y->right;
        }
        //y に子供がいればｙの親とｙの子供の親にする
        if(x != NULL)
        {  
            x->parent = y->parent;
        }
            
    }else{//ｙが両サイドに子供を持つときの処理-------------------------
        //yに両方子供がいているので削除準備
        y = GetSuccessor(z);//zが二つの子供を子供を持つ場合はｚの次接点を削除対象へ
    }

    //共通処理-----------------------------------------
    //yの親 にｘの情報を記憶させる
    if(y->parent == NULL)//ｙがRootであるとき
    {
        g_root = x;//かわりにｘが次のRootとなる
    }else if(y == y->parent->left){
        y->parent->left = x;//ｙが左側の子供の時ｙのかわりにその子供を設置
    }else{
        y->parent->right = x;//ｙが右側の子供のときｙのかわりにその子供を設置
    }
    //二人の子供がいているときのみの処理--------------------
    if(y != z)
    {
        z->id = y->id;//ノードの形は変えずにiDだけをコピーして、付け替えた体にする
        //ｙがｚの直下でない時だけやる処理
        if(y->parent != z)
        {
            y->parent->left = y->right;
            y->right = y->parent;
        }
    }
    free(y);
    return NULL;
}

NodePointer GetSuccessor(NodePointer z)
{
    z = z->right;
    while(z->left != NULL)z=z->left;
    return z;
}