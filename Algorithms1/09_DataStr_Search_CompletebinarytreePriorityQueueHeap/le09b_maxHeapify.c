#include <stdio.h>
#include <stdlib.h>

int heap_size = 0;
void maxHeapify(int *A,int i)
{
    int k_l,k_r;
    int largest;
    k_l = i * 2 + 1;
    k_r = i * 2 + 2;
    //most lagest node we select
    if(k_l < heap_size && A[k_l] > A[i]){
        //largest heap index
        largest = k_l;
    }else{
        largest = i;
    }
    if(k_r < heap_size && A[k_r] > A[largest]){
        largest = k_r;
    }

    //if the value we instructed is not in an proper place
    //we execute this function again
    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(A,largest);//交換後に整合性を保てないかもしれないのでノード整列のために再起的に行う
    }
}

void buildMaxHeap(int *A){
    for(int i = (heap_size / 2) - 1; i >= 0 ; i--){
        maxHeapify(A,i);
    }
}

int main()
{
    int *H;
    int n;
    int k_p,k_l,k_r;
    scanf("%d", &n);
    heap_size = n;
    H = (int *)malloc(sizeof(int) * n);
    for(int j = 0 ; j < n ; j++)
    {
        //input values
        scanf("%d", &H[j]);
    }
    buildMaxHeap(H);

    for(int i = 0; i < n; i++)
    {
        printf(" %d",H[i]);
    }
    printf("\n");
    return 0;
}