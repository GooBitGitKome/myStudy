#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int parent;
    int id;
    struct node* left_child;
    struct node* right_siblings;
    int depth;
}*Node;

struct node * PreParse(struct node*);
void Display(struct node*, int n);
int depth = -1;

int main()
{
    int n, id,degrees,child_id;
    int left_node;
    struct node* rootNode;
    scanf("%d",&n);
    Node = (struct node *)malloc(sizeof(struct node) * n);
    //親に初期値を定める,下記入力後-1の値のノードがただ一つに定まりそれがRootである
    for(int i = 0 ; i < n ; i++){
        Node[i].parent = -1;
    }

    for(int i = 0 ;  i < n ; i++)
    {
        scanf("%d", &id);
        Node[id].id = id;
        scanf("%d",&degrees);
        left_node = 0;
        for(int j = 0; j < degrees ; j++)
        {
            scanf("%d",&child_id);
            Node[child_id].parent = id;
            Node[child_id].id = child_id;
            if(j == 0){
                //the first node is to go down next branch,
                Node[id].left_child = &Node[child_id];
                left_node = child_id;
            }else{
                //if there are siblings, record the number to before left one
                Node[left_node].right_siblings = &Node[child_id];
                left_node = child_id;
            }
        }
    }
    // Root Nodeを検索
    for(int i = 0; i < n ; i++){
        if(Node[i].parent == -1)rootNode = &Node[i];
    }
    PreParse(rootNode);
    Display(Node,n);
    return 0;
}

//recursive function
// node 0: parent = -1, depth = 0, root, [1, 4, 10]
//RootNodeのみを引数として受け取り再起して遡っていく
struct node * PreParse(struct node * Node)
{
    //深度計算
    if(Node == NULL){
        depth--;
        return NULL;
    }
    depth++;
    Node->depth = depth;

    PreParse(Node->left_child);
    PreParse(Node->right_siblings);
    return NULL;
}
//配列としてNodeを受け取る
void Display(struct node* Node,int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(Node[i].parent == -1)
        {
            printf("node %d: parent = %d, depth = %d, root, ", Node[i].id,Node[i].parent, Node[i].depth);
            printf("[");
            for(struct node* loopNode = Node[i].left_child; loopNode != NULL ; loopNode = loopNode->right_siblings)
            {
                printf("%d", loopNode->id);
                if(loopNode->right_siblings != NULL)printf(", ");
            }
            printf("]\n");
        }else if(Node[i].left_child != NULL){
            printf("node %d: parent = %d, depth = %d, internal node, ", Node[i].id,Node[i].parent, Node[i].depth);
            printf("[");
            for(struct node* loopNode = Node[i].left_child; loopNode != NULL ; loopNode = loopNode->right_siblings)
            {
                printf("%d", loopNode->id);
                if(loopNode->right_siblings != NULL)printf(", ");
            }
            printf("]\n");
        }else{
            printf("node %d: parent = %d, depth = %d, leaf, []\n", Node[i].id,Node[i].parent, Node[i].depth);    
        }

    }
}