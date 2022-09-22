#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *A;
    int max;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n + 1);// A[n] is used to have minimum value
    for(int i = 1 ; i < n ; i++)
    {
        if(i == 1){
            scanf("%d",&A[i-1]);
            scanf("%d",&A[i]);
            A[n] = A[i-1];//initialize minimum number
            max = A[i] - A[n];//initialize maximum value
            if(A[i] < A[n]) A[n] = A[i];//make minimum num
            // printf("%d\n",max);
            continue;
        }

        scanf("%d",&A[i]);
        //printf("%d %d\n",A[i],A[n]);
        if((A[i] - A[n]) > max)max = (A[i] - A[n]);
        //printf("%d\n",max);
        if(A[i] < A[n]) A[n] = A[i];//make minimum num
    }
    printf("%d\n",max);
    return 0;
}