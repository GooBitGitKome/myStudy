#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_HEAP 2000000
int heap_size = -1;
//adjust each branch to make it maximum in the separated tree
//recursive function
void maxHeapify(int *A,int i)
{
    int k_l,k_r;
    int largest;
    k_l = i * 2 + 1;
    k_r = i * 2 + 2;
    //most lagest node we select
    if(k_l <= heap_size && A[k_l] > A[i]){
        //largest heap num
        largest = k_l;
    }else{
        //same above
        largest = i;
    }
    if(k_r <= heap_size && A[k_r] > A[largest]){
        largest = k_r;
    }
    //if the value we instructed is not in an proper place
    //we execute this function again and again
    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(A,largest);
    }
}

void buildMaxHeap(int *A){
    for(int i = ((heap_size+1) / 2) ; i >= 0 ; i--){
        maxHeapify(A,i);
    }
}
int getParent(int key)
{
    // 0 origine
    return (key - 1 ) / 2;
}
int getLeft(int key)
{
    return 2 * key + 1;
}
int getRight(int key)
{
    return 2 * key + 2;
}


void heapIncreaseKey(int *A, int i, int key)
{   
    if(key < A[i]){}//actually if this is applied,it is error as the key value smaller than current key;
    A[i] = key;
    //check the new key is whether greater than the parent
    while(i > 0 && A[getParent(i)] < A[i])
    {
        int tmp = A[i];
        A[i] = A[getParent(i)];
        A[getParent(i)] = tmp;
        //go up;
        i = getParent(i);
    }
}
void Insert(int *A , int key)
{
    //形式的にヒープ値と挿入予定位置に値を入れておく
    heap_size++;
    A[heap_size] = INT_MIN;
    //ヒープ値設定
    heapIncreaseKey(A,heap_size,key);
    
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
    maxHeapify(A,0);
    return max;
}
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