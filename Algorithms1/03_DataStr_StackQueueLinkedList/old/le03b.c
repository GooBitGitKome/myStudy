#include <stdio.h>
#include <stdlib.h>
#define DEBUGPRINT     for(i = 0; i < n ; i++){printf("input %s : %d\n" , arry[i].name, arry[i].time);}
#define DEBUGTEST   struct queElm test = deque(arry);printf("check queElm : %s : %d\n",test.name,test.time);
#define DEBUGTEST1   printf("check queElm : %s : %d\n",arry[0].name, n);
#define DEBUFPRINT1 printf("check flow:\n");
struct queElm{
    char name[10];//1 ≤ time[i] ≤ 50,000 + 1 ≤ timei の合計 ≤ 1,000,000
    int time;//1 ≤ 文字列 namei の長さ ≤ 10
};
typedef struct queElm *ElmPointer;

int isEmpty();//return true = 1 , false = 0
int isFull();//return true = 1 , false = 0
ElmPointer creque();//create que which has the scale of [int], returns struct arry pointer
struct queElm deque(ElmPointer arry);
void enque(ElmPointer,struct queElm);
int exeProcess(ElmPointer,ElmPointer,int q);

int head = 0, tail = 0,n = 0;

int main()
{
    int i;
    int q;//1 ≤ q ≤ 1,000
    scanf("%d%d",&n,&q);//input process number and quantum time
    ElmPointer arry = creque();//create struct queElm array with the size of [n]
    ElmPointer finishedElmArry = creque();//stored finished procecces
    tail = 0;

    //set the values to arry
    for(i = 0 ; i < n ; i++){
        scanf("%s%d", arry[i].name, &arry[i].time);
    }
    //Process function-------------------------------
    exeProcess(arry,finishedElmArry,q);
    //-----------------------------------------------
    for(i = 0 ; i < n ; i++)
    {
        printf("%s %d\n", finishedElmArry[i].name,finishedElmArry[i].time);
    }
    return 0;
}

ElmPointer creque()
{
    return (ElmPointer)malloc(sizeof(struct queElm) * n );
}

void enque(ElmPointer arry, struct queElm elm)
{
    arry[tail] = elm;
    tail = (tail +1 ) % n;
}

struct queElm deque(ElmPointer arry)
{
    int tmp;
    tmp = head;
    head = (head + 1) % n;//the first element move to next to now head;
    return arry[tmp];
}

int exeProcess(ElmPointer arry,ElmPointer finishedElmArry, int q)
{
    int i=0;
    int qsum = 0;
    struct queElm tmp;

    while(qsum <1000000 || i < n)
    {
        if((arry[head].time - q)<= 0){
            qsum += arry[head].time;
            arry[head].time  = qsum;
            // at the end of the process this procedure is moved to finished arry and dequed from arry[]
            finishedElmArry[i] = deque(arry);
            i++;
        }else{
            //When the process is unable to finish
            qsum += q;
            arry[head].time -= q;
            enque(arry,deque(arry));
        }
    }
    return 0;
}
