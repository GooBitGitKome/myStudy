#include <stdio.h>
#include <stdlib.h>

long cnt;
int j = 0;
int G[100];

void InsertionSort(int *A,int n,int g)
{
    int key,j;
    for(int i = g; i < n ; i++)
    {
        key = A[i];
        j = i - g;
        
        while(j >= 0 && A[j] > key)
        {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = key;
    }
}

void ShellSort(int *A,int n)
{
    //Gap用の数列生成
    for(j = 0; ; j++)
    {
        if( (3 * j + 1) <= n) G[j] = (3 * j + 1);
        else break;
        printf("%d \n", G[j]);
    }

    for(int i = j-1 ; i >= 0 ; i--)
    {
        InsertionSort(A, n, G[i]);
    }
}

void Display(int *A , int n)
{
    printf("%d\n",j);
    for(int i = j-1 ; i >= 0 ; i--)
    {
        printf("%d",G[i]);
        if((i-1) == 0) printf(" ");
        else printf("\n");
    }
    printf("%ld\n",cnt);
    for(int i = 0; i < n ; i++)
    {
        printf("%d\n",A[i]);
    }
}

int main()
{
    int n;
    int *A;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    //input values
    for(int i = 0 ; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    ShellSort(A,n);
    //Display(A,n);
    return 0;
}

