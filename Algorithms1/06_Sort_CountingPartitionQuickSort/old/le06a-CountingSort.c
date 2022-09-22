// Counting-Sort(A, B, k)
// 1    for i = 0 to k
// 2        do C[i] = 0
// 3    for j = 1 to length[A]
// 4        do C[A[j]] = C[A[j]]+1
// 5    /* C[i] now contains the number of elements equal to i */
// 6    for i = 1 to k
// 7    do C[i] = C[i] + C[i-1]
// 8    /* C[i] now contains the number of elements less than or equal to i */
// 9    for j = length[A] downto 1
// 10       do B[C[A[j]]] = A[j]
// 11          C[A[j]] = C[A[j]]-1

#include <stdio.h>
#include <stdlib.h>

#define K 10001
int n;//length of A and B
void CountingSort(int *A , int *B, int k);
int main()
{
    int i,j;
    int *A;
    int *B;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int)* n);
    B = (int *)malloc(sizeof(int)* n +1);
    for(i = 0 ; i < n ; i++){
        scanf("%d", &A[i]);
    }

    CountingSort(A,B,K);

    //B配列はインデックス番号１〜N＋１番目に格納される（CountingSortingの特徴）
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
    int C[K];
    int i,j;
    //initializing Counting Array C
    for(i = 0; i< K ; i++)C[i] = 0;
    //Counting A[i]'s number relating to C's index
    for(i = 0; i< n ; i++)C[A[i]]++;
    for(i = 1; i < K ; i++){
        C[i] = C[i] + C[i-1];
        //printf("%d :%d \n", i-1 , C[i-1]);
    }
    for(i = n-1 ; i >= 0 ; i--){
        B[C[A[i]]] = A[i];
        //printf("%d : %d \n",C[A[i]],A[i]);
        C[A[i]]--;
    }
}