#include <stdio.h>
#include <stdlib.h>
//Prototype declaration
int Hoare_Partition(int*,int p,int r);

#if DEBUG
int main()
{
    int n;
    int *A;
    int sepIndex;//separator's index
    // take the input number of the length of the next input Array
    scanf("%d", &n);
    //make the array which has the length of [n]
    A = (int * )malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++)
    {
        //input val and enter it in A[i]
        scanf("%d", &A[i]);
    }
    //Partition(Array I want to sort, leftside index, right sideindex):this function the scale is[l,r]:containing r
    //return the value of separation position in A
    sepIndex = Partition(A,0,n-1);
    
    //Display
    for(int i = 0; i < n ; i++)
    {
        if(i == sepIndex)printf("[%d]", A[i]);//print the separation point
        else printf("%d", A[i]);
        if(i+1 != n)printf(" ");
    }
    printf("\n");
    
    return 0;
}
#endif

//l = leftside index , r = right index, caution: r is not [p,r) but [p,r]
int Hoare_Partition(int* A,int p,int r)
{
    int x = A[p];//pivot
    int i = p;
    int j = r;
    int swap;
    while(1)
    {
        //i <= p <= j are A[]'s index
        //we want the pivot is neither MAX nor MIN
        for(; A[j] <= x; j--);
        for(; A[i] >= x; i++);
        if(i < j)
        {
            swap = A[j];
            A[j] = A[i];
            A[i] = swap;
        }else{
            return j;
        }
    }
}