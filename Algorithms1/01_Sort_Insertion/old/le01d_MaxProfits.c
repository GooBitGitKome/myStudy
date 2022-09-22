#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    int *A;
    int key;
    int i =0;

    //the number of times input
    scanf("%d", &n);
    //array[n] = Sentinel && storage for minimum;
    A = (int *)malloc(sizeof(int) * n + 2);

    scanf("%d",&A[0]);
    scanf("%d",&A[1]);
    A[n] = A[0];//the initialize minimum number as the first value of A[]
    A[n + 1] = A[1] - A[0];//the initialize maximum number as the first value of A[]
    for(i = 2 ; i < n ; i++)
    {
        //renew the minimum
        if(A[i-1] < A[n]){
            A[n] = A[i-1];
        }
        //input value and check maximum
        scanf("%d",&A[i]);
        if((A[i] - A[n]) > A[n+1]){
            A[n+1] = A[i] - A[n];
        }
    }

    printf("%d\n", A[n+1]);
    return 0;
}