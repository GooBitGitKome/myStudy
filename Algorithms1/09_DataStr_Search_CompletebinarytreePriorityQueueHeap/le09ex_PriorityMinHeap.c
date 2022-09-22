#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_HEAP 2000000

//prototype declaration
void MinHeapify(int *,int i);
void BuildMinHeap(int *);
int GetParent(int );
int GetRight(int );
int GgetLeft(int );
void Insert(int *, int );
void HeapIncreaseKey(int * ,int);
int Extract(int *);

//global variables
int heap_size = -1;

int main()
{
    char cmd[10];
    int key;
    int A[MAX_HEAP];
    while(1)
    {
        scanf("%s", cmd);
        if(cmd[0] == 'i'){
            scanf("%d",&key);
            Insert(A,key);
        }else if(cmd[0] == 'e' && cmd[1] =='x'){
            printf("%d\n",Extract(A));
        }else{
            break;
        }
    }
    return 0;
}

//adjust each branch to make it maximum in the separated tree
//recursive function
//Priority queue--------------------
//----------------------------------
//----------------------------------
//----------------------------------
//----------------------------------
//adjust each branch to make it maximum in the separated tree
//recursive function
void MinHeapify(int *A,int i)
{
    int k_l,k_r;
    int smallest;
    k_l = i * 2 + 1;
    k_r = i * 2 + 2;
    //most lagest node we select
    if(k_l <= heap_size && A[k_l] < A[i]){
        //smallest heap num
        smallest = k_l;
    }else{
        //same above
        smallest = i;
    }
    if(k_r <= heap_size && A[k_r] < A[smallest]){
        smallest = k_r;
    }
    //if the value we instructed is not in an proper place
    //we execute this function again
    if(smallest != i){
        int tmp = A[i];
        A[i] = A[smallest];
        A[smallest] = tmp;
        MinHeapify(A,smallest);
    }
}

void BuildMinHeap(int *A){
    for(int i = ((heap_size+1) / 2) ; i >= 0 ; i--){
        MinHeapify(A,i);
    }
}
int GetParent(int key)
{
    // 0 origine
    return (key - 1 ) / 2;
}
int GetLeft(int key)
{
    return 2 * key + 1;
}
int GetRight(int key)
{
    return 2 * key + 2;
}
void Insert(int *A , int key)
{
    //作成されたヒープのサイズを増やす
    heap_size++;
    //初期値に最大値を挿入
    A[heap_size] = INT_MAX;
    //ヒープ値設定
    HeapIncreaseKey(A,key);
}
void HeapIncreaseKey(int *A,int key)
{
    int i = heap_size;
    int tmp;
    if(key > A[i])return;
    heap_size++;
    A[i] = key;
    while(i > 1 && A[GetParent(i)] > A[i] )
    {
        tmp = A[GetParent(i)];
        A[GetParent(i)] = A[i];
        A[i] = tmp;
        i = GetParent(i);
    }
}

int Extract(int *A)
{
    int max;
    if(heap_size < 0){
        //out put error
    }
    max = A[0];
    A[0] = A[heap_size];
    heap_size--;
    //adjust A depend on heap tree
    MinHeapify(A,0);
    return max;
}
//----------------------------------
//----------------------------------
//----------------------------------
//----------------------------------
//----------------------------------