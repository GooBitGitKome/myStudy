#include <stdio.h>
#include <stdlib.h>
// define
#define K 10001
// gloval variables
int n;//the number of input val
//prototype declaration
void CountingSort(int *A , int *B, int k);

int main()
{
    int i,j;
    int *A;//contains input vals
    int *B;//the final sorted numbers entered
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int)* n);
    B = (int *)malloc(sizeof(int)* n +1);
    //input val enter in A
    for(i = 0 ; i < n ; i++){
        scanf("%d", &A[i]);
    }

    //counting sort
    CountingSort(A,B,K);

    //display
    for(i = 1 ; i < n + 1 ;i++)
    {
        printf("%d",B[i]);
        if(i+1 != (n + 1))printf(" ");
    }
    printf("\n");
    return 0;
}

void CountingSort(int *A , int *B, int k)
{
    int C[K];//array for the counting, A[]'s values is used as C[]'s index and count
    int i,j;
    //initializing-----------------------------------------
    for(i = 0; i< K ; i++)C[i] = 0;
    //initializing-----------------------------------------
    //Counting A[i]'s number relating to C's index
    for(i = 0; i< n ; i++)C[A[i]]++;
    //important part of Counting sort
    for(i = 1; i < K ; i++){
        // カウントした値を元に格納する配列のインデックス番号を作成
        C[i] = C[i-1] + C[i];// i = 1 ~ k-1
    }
    for(i = 0; i < n ; i++){
        B[C[A[i]]] = A[i];
        C[A[i]]--; // count down,for same values in A[]
    }
}