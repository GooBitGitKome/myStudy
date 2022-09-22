#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name[11];
    int val;
}QueueStructure;

void Enqueue(QueueStructure *Q,char name[10],int val,int n);
QueueStructure Dequeue(QueueStructure *Q,int n,int flg);//flg is used to check the dequeued value is displayed
void Display(QueueStructure *Q, int n);
int isEmpty(QueueStructure*,int);
void RoundRobin(QueueStructure *Q, int n, int quantum);
int Q_tail = 0;
int Q_head = 0;
int main()
{
    int n,quantum;
    char name[11];
    int val;
    scanf("%d",&n);
    scanf("%d",&quantum);
    QueueStructure *Q = (QueueStructure *)malloc(sizeof(QueueStructure) * n + 1);
    Q[n].val = 0;// used to check the queue array full or not; full > 0 ; empty = 0
    
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",name);
        scanf("%d",&val);
        Enqueue(Q,name,val,n);//input the value to Array
    }

    RoundRobin(Q,n,quantum);
    //Display(Q,n);
    return 0;
}

void Enqueue(QueueStructure *Q,char *name,int val,int n)
{
    strcpy(Q[Q_tail].name,name);
    Q[Q_tail].val = val;
    Q_tail = (Q_tail + 1) % n;
    //full check value
    Q[n].val++;
}

QueueStructure Dequeue(QueueStructure *Q,int n,int flg)
{
    int tmp_index = Q_head;
    //full check value
    Q[n].val--;
    //Slide the head
    Q_head = (Q_head+1) % n;

    // print and return the top value
    if(flg==1)printf("%s %d\n",Q[tmp_index].name,Q[tmp_index].val);
    return Q[tmp_index];
}
//check empty or ful
int isEmpty(QueueStructure *Q ,int n){
    if(Q[n].val == 0)return -1;
    return 0;
}

void Display(QueueStructure *Q, int n)
{
    int j = Q_tail;
    for(int i = 0; i < n ; i++ )
    {
        printf("%s %d\n",Q[j].name,Q[j].val);
        j = (j + 1) % n;
    }
}

void RoundRobin(QueueStructure *Q, int n, int quantum)
{
    QueueStructure tmp;
    for(int total = 0 ; ;)
    {
        //printf("%d total:\n",total);
        if((Q[Q_head].val - quantum) <= 0)//when the task is able to finish within the quantum time
        {
            //calc total time
            total += Q[Q_head].val;

            //enter the total time
            Q[Q_head].val = total; 
            //Deque and display the task;
            Dequeue(Q,n,1);
            if(isEmpty(Q,n) == -1) break;
            
        }else{
            //calc total time
            total += quantum;

            //Queue value moves to the last in the array
            Q[Q_head].val -= quantum;
            tmp =Q[Q_head];
            Dequeue(Q,n,0);
            Enqueue(Q,tmp.name,tmp.val,n);
        }
    }
}