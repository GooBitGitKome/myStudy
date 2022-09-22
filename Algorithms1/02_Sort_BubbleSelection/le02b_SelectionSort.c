#include <stdio.h>
#include <stdlib.h>
int * selectionSort(int *A,int n)
{
    int min,tmp;
    
    for(int i = 0 ; i< n;i++)
    {
        min = i;
        for(int j = i ; j < n ; j++)
        {
            if(A[min] > A[j])min = j;
        }
        if(min == i)continue;
        A[n]++;//count the number of swap
        tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
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
    A = selectionSort(A,n);
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