#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DblyLL{
    int key;
    struct DblyLL *next;
    struct DblyLL *prev;
};
typedef struct DblyLL * NodePointer;


void Insert(int);
void Delete(int);
NodePointer Search(int);
void DeleteFirst();
void DeleteLast();

void Execute();
void DisplayAllKey();

//Sentinela
NodePointer head;

//variables
int commandTimes; // the number of times
    char commandList[4][12] = {{"insert"},{"delete"},{"deleteFirst"},{"deleteLast"}};

int main()
{
    //initialize
    head = (NodePointer)malloc(sizeof(NodePointer));
    head->next = head;
    head->prev = head;
    
    //input
    scanf("%d",&commandTimes);
    //implemante
    Execute();
    //display
    DisplayAllKey();

    return 0;
}

void Execute()
{
    //variables 
    int i; // loop counter
    char commandString[12];
    int key;
    NodePointer node;

    for(i = 0 ; i < commandTimes ; i++){
        scanf("%s",commandString);
        //insert
        if(strcmp(commandString,commandList[0]) == 0){
            //input the key
            scanf("%d",&key);
            Insert(key);
        }
        //delete
        if(strcmp(commandString,commandList[1]) == 0){
            //input the key
            scanf("%d",&key);
            Delete(key);
        }        
        //deleteFirst
        if(strcmp(commandString,commandList[2]) == 0){
            DeleteFirst();
        }
        //deleteLast
        if(strcmp(commandString,commandList[3]) == 0){
            DeleteLast();
        }        

        
    }
}

void Insert(int key)
{
    NodePointer node;
    NodePointer newnode = (NodePointer)malloc(sizeof(struct DblyLL));
    newnode->next = head->next;
    newnode->prev = head;
    head->next->prev = newnode;    
    head->next = newnode;
    newnode->key = key;
    if(head->next == head){
        head->prev = newnode;
    }
}

void Delete(int key)
{
    NodePointer node;
    if((node = Search(key)) != NULL){
        if(node->next == head){
            // Link the last node and head each other
            head->prev = node->prev;
            node->prev->next = head;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if(node!=head){
            free(node);
        }
        
    }
}

NodePointer Search(int key)
{
    NodePointer node;
    for(node = head->next ; node != head ; node = node->next)
    {   
        //when the key is discovered
        if(node->key == key){return node;}         
    }
    //if there is not the key
    return NULL;
}

void DisplayAllKey()
{
    NodePointer node;
    for(node = head->next ; node != head ; node = node->next)
    {   
        printf("%d",node->key);
        if(node->next != head)printf(" "); 
        
             
    }
    printf("\n");
}

void DeleteFirst()
{
    NodePointer delNode = head->next;
    if(delNode!=head){
        delNode->next->prev = head;
        head->next = delNode->next; 
        free(delNode);
    }  
}

void DeleteLast()
{
    NodePointer delNode = head->prev;
    if(delNode!=head){
        // Link the last node and head each other
        head->prev = delNode->prev;
        delNode->prev->next = head;

        delNode->prev->next = head;
        head->prev = delNode->prev;  
        free(delNode);
    }  
}