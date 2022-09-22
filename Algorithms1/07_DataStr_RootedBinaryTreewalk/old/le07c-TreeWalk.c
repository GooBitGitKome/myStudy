#include <stdio.h>
#include <stdlib.h>

#define LINEVALUES 3
struct NODE{
    int key;
    int degree;
    int depth;
    int height;
    struct NODE* parent;
    struct NODE* left;
    struct NODE* right;
    struct NODE* sibling;
};
typedef struct NODE* NodePointer;
struct NODE dummy_root;
struct NODE dummy_sibling;
NodePointer nodeArray;
int depth  = -1;
int maxDepth = 0;

void Display(NodePointer, int);
void SetDepth(NodePointer nodeArray, NodePointer node);
int SetHeight(NodePointer node);
void TreeWalkPreorder(NodePointer nodeArray, NodePointer node);
void TreeWalkInorder(NodePointer nodeArray, NodePointer node);
void TreeWalkPostorder(NodePointer nodeArray, NodePointer node);

int main()
{
    //input the all trees*************************************
    int n;// the number of all nodes;
    int key,left_key,right_key;
    NodePointer tmpNode;
    NodePointer nodeArray;
    dummy_root.key = -1;
    dummy_root.sibling = NULL;
    dummy_sibling.key = -1;

    scanf("%d", &n);
    nodeArray = (NodePointer)malloc(sizeof(struct NODE) * n);
    // input informatin of Tree
    //in lecture 07's this problem, the tree is binary.
    for(int i = 0 ; i < n ; i++)
    {
        //catch three values in a line 
        //main node----------------------------
        scanf("%d",&key);
        //配列のインデックスとkeyを同一と考える
        //nodeArray[key] = MakeNode(key);
        nodeArray[key].key = key;
        //left child----------------------------
        //left childがなければさくせい、あればスルー
        scanf("%d",&left_key);
        // if(left_key != -1 && nodeArray[left_key] ){
        //     //nodeArray[left_key] = MakeNode(left_key);
        // }else 
        if(left_key == -1){//if left_key is -1, it means not to have left one;
            nodeArray[key].left = NULL;
        }else{
            //setting child
            nodeArray[key].left = &nodeArray[left_key];
            //setting left_key's parent
            nodeArray[left_key].parent = &nodeArray[key];
        }

        //right child----------------------------
        //left childがなければさくせい、あればスルー
        scanf("%d",&right_key);
        // if(right_key != -1 && nodeArray[right_key] ){
        //     //nodeArray[right_key] = MakeNode(right_key);
        // }else 
        if(right_key == -1){//if right_key is -1, it means not to have left one;
            nodeArray[key].right = NULL;           
        }else{
            //setting child
            nodeArray[key].right = &nodeArray[right_key];
            //setting right_key's parent
            nodeArray[right_key].parent = &nodeArray[key];
        }
        //setting siblings
        if(left_key != -1 && right_key != -1){
            nodeArray[key].left->sibling = &nodeArray[right_key];
            nodeArray[key].right->sibling = &nodeArray[left_key];
        }

        //setting degree;
        nodeArray[key].degree += (left_key != -1)? 1 : 0;
        nodeArray[key].degree += (right_key != -1)? 1 : 0;

    }
    // for(int i = 0 ; i < n ; i++)
    // // {
    // //     printf("test %d\n", nodeArray[i].left->key);
    // //     if(nodeArray[i].left == NULL){
    // //         printf("test %d\n", -1);
    // //     }
    // // }

    //display ******************************************************
    Display(nodeArray,n);
    return 0;
}

void Display(NodePointer nodeArray,int n)
{
    NodePointer root;
    for(int i = 0 ; i < n ; i++)
    {
        if(nodeArray[i].parent== NULL){//it means root, do not have parent
            nodeArray[i].parent = &dummy_root;
            root = &nodeArray[i];
        }
        if(nodeArray[i].sibling == NULL){//if no siblings, set the dummy sibling having the value -1;
            nodeArray[i].sibling = &dummy_sibling;
        }
    }
    // SetDepth(nodeArray,root);
    // SetHeight(root);
    // root->height = maxDepth;
    // for(int i = 0; i  < n ; i++)
    // {
    //     printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
    //         ,nodeArray[i].key, nodeArray[i].parent->key, nodeArray[i].sibling->key,nodeArray[i].degree
    //         , nodeArray[i].depth, nodeArray[i].height);
        
    //     if(nodeArray[i].parent->key == -1)printf("root\n");
    //     else{
    //         if(nodeArray[i].degree != 0)printf("internal node\n");
    //         else printf("leaf\n");
    //     }
        
    // }
    printf("Preorder\n");
    TreeWalkPreorder(nodeArray,root);
    printf("\n");

    printf("Inorder\n");
    TreeWalkInorder(nodeArray,root);
    printf("\n");

    printf("Postorder\n");
    TreeWalkPostorder(nodeArray,root);
    printf("\n");
}
// NodePointer MakeNode(int key)
// {
//     NodePointer newnode;
//     newnode = (NodePointer)malloc(sizeof(struct NODE));
//     newnode->key = key;
//     //initializing of Parent
//     //it is not decided yet , so have NULL as parent
//     newnode->parent = NULL;

//     return newnode;
// }

void SetDepth(NodePointer nodeArray, NodePointer node)
{
    if(node == NULL){
        //end requirement
    }else{
        depth++;
        if(maxDepth < depth) maxDepth = depth;
        node->depth = depth;
        SetDepth(nodeArray, node->left);
        SetDepth(nodeArray, node->right);
        depth--;
    }
}

int SetHeight(NodePointer node)
{
    int h1,h2;
    h1 = h2 = 0;
    if(node->left != NULL){
        h1 = SetHeight(node->left) + 1;
    }
    if(node->right != NULL){
        h2 = SetHeight(node->right) + 1;
    }
    return node->height = (h1 > h2)? h1:h2;
}

void TreeWalkPreorder(NodePointer nodeArray, NodePointer node)
{
    if(node == NULL){
        //end requirement
    }else{
        printf(" %d", node->key);
        TreeWalkPreorder(nodeArray, node->left);
        TreeWalkPreorder(nodeArray, node->right);
    }
}

void TreeWalkInorder(NodePointer nodeArray, NodePointer node)
{
    if(node == NULL){
        //end requirement
    }else{
        
        TreeWalkInorder(nodeArray, node->left);
        printf(" %d", node->key);
        TreeWalkInorder(nodeArray, node->right);
    }
}
void TreeWalkPostorder(NodePointer nodeArray, NodePointer node)
{
    if(node == NULL){
        //end requirement
    }else{
        
        TreeWalkPostorder(nodeArray, node->left);
        TreeWalkPostorder(nodeArray, node->right);
        printf(" %d", node->key);
    }
}