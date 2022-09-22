#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Structure
struct Node{
    int key;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node* NodePointer;
//Prottype declaration
NodePointer Insert(int key);
void Delete(int key);
void DeleteFirst();
void DeleteLast();
NodePointer Findkey(int key);
//Global variables
NodePointer head;

int main()
{
    //initializing----
    head = (NodePointer)malloc(sizeof(struct Node));
    head->prev = head;
    head->next = head;
    //-----------------
    int n,key;
    char cmd[12];
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",cmd);
        if(cmd[0] == 'i'){
            //insert
            //input key
            scanf("%d",&key);
            Insert(key);

        }else if(strcmp(cmd,"delete") == 0){
            //delete
            //input key
            scanf("%d",&key);
            Delete(key);
        }else if(strcmp(cmd,"deleteFirst") == 0){
            DeleteFirst();
        }else if(strcmp(cmd,"deleteLast") == 0){
            DeleteLast();
        }
    }
    for(NodePointer i = head->next; i != head ; i = i->next )
    {
        printf("%d", i->key);
        if(i->next != head)printf(" ");
    }
    printf("\n");

    free(head);
    return 0;
}

NodePointer Insert(int key)
{
    NodePointer newnode = (NodePointer)malloc(sizeof(struct Node));
    newnode->key = key;
    //connection to head node
    //if newnode is the first one node to insert the head
    //it's next must be head, and head previous is the newn one
    if(head->next == head){//important---------
        newnode->next = head;
        newnode->prev = head;
        head->prev = newnode;
        head->next = newnode;
    }else{//-----------------------------------
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
    }
    return newnode;
}
void Delete(int key)
{
    NodePointer del_node;
    if((del_node = Findkey(key)) != NULL)
    {
        //when there is node having the key;
        //Delete del_node
        del_node->next->prev = del_node->prev;
        del_node->prev->next = del_node->next;
        free(del_node);
    }
}

NodePointer Findkey(int key)
{
    for(NodePointer i = head->next; i != head ; i = i->next )
    {
        if(i->key == key)return i;
    }
    return NULL;
}

void DeleteFirst()
{
    NodePointer del_node = head->next;
    //be careful of the time when Delete node is the last one node without head node
    if(del_node != head){
        //When Del node is the last one
        if(del_node->next == head){
            head->next = head;
            head->prev = head;
        }else{
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
        }
        free(del_node);
    }
}

void DeleteLast()
{
    NodePointer del_node = head->prev;
    if(del_node != head){
        del_node->prev->next = head;
        head->prev = del_node->prev;
        free(del_node);
    }
}