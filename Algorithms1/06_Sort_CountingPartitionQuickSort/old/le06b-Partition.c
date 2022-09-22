#include <stdio.h>
#include <stdlib.h>

int Partition(int*,int p,int r);

int main()
{
    int n;
    int *A;
    int sepIndex;//separator's index
    // take the input number of the length of the next input Array
    scanf("%d", &n);
    //make the array having the length of [n]
    A = (int * )malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &A[i]);
    }
    sepIndex = Partition(A,0,n-1);
    
    for(int i = 0; i < n ; i++)
    {
        if(i == sepIndex)printf("[%d]", A[i]);
        else printf("%d", A[i]);
        if(i+1 != n)printf(" ");
    }
    printf("\n");
    
    return 0;
}

//p = leftside index , r = right index, caution: r is not [p,r) but [p,r]
int Partition(int* A,int p,int r)
{
    int x = A[r];// pivot
    int tmp;
    int s = p -1;
    for(int i = p ; i < r; i++)
    {
        if(A[i] <= x){
            s++;
            tmp = A[s];
            A[s] = A[i];
            A[i] = tmp;
        }
    }
    s++;
    tmp = A[s];
    A[s] = A[r];
    A[r] = tmp;
    //return the value of separator
    return s;
}