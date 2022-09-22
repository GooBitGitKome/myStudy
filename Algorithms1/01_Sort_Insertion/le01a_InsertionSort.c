#include <stdio.h>
#include <stdlib.h>
int* insertionSort(int *, int);

int main()
{
    int n,j;
    int *A;// sequence of values
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    //input the values
    for(int i = 0 ; i < n ; i++)scanf("%d",&A[i]);
    A = insertionSort(A,n);
    free(A);
    return 0;
}

int * insertionSort(int *A,int n)
{
    int j,key;
    //1 to the last of n
    for(int i = 1 ; i < n ; i++)
    {
        //debug display------
        for(int s = 0 ; s < n ; s++)
        {
            printf("%d", A[s]);
            if(s+1 != n)printf(" ");
        }
        printf("\n");
        // ---------------------

        key = A[i];//key is A[i]
        j = i -1;//j is i -1 to 0
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];  
            j--;
        }
        A[j+1] = key;
    }

    //debug display------
        for(int s = 0 ; s < n ; s++)
        {
            printf("%d", A[s]);
            if(s+1 != n)printf(" ");
        }
        printf("\n");
        // ---------------------
    return A;
}