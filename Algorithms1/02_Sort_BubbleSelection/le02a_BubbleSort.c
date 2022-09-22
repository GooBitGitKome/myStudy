#include <stdio.h>
#include <stdlib.h>

int * bubbleSort(int *A, int len){
    int tmp;
    for(int i = 0; i < len ; i++)
    {
        for(int j = len -1; j > i; j--)
        {            
            if(A[j] < A[j-1])//swap
            {
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                A[len]++;
            }
        }
    }
    return A;
}

int main()
{
    int *A;
    int n;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int)*n + 1);//A[n] is used to stock the time to swap
    A[n] = 0;
    for(int i = 0 ; i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    //execute bubble sort
    A = bubbleSort(A,n);
    //display
    for(int i = 0 ; i<n;i++)
    {
        printf("%d",A[i]);
        if(i + 1 != n)printf(" ");
    }
    printf("\n");
    printf("%d\n", A[n]);

    free(A);
    return 0;
}