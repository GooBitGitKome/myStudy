#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int count = 0;
void Merge(int *A, int left, int mid, int right)
{
    int i,j,k;
    int n1 = mid -left;
    int n2 = right -mid;
    int *L;
    int *R;

    //Adding 1 for a sentinel
    L = (int *)malloc(sizeof(int) * (n1 + 1));
    R = (int *)malloc(sizeof(int) * (n2 + 1));
    for(i = 0 ; i < n1 ; i++){
        L[i] = A[left + i];
    }
    for(i = 0 ; i < n2 ; i++){
        R[i] = A[mid + i];
    }

    //set sentinel
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    for(k = left, i = j = 0 ; k < right ; k++)
    {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            count++;//global variables
        }else{
            A[k] = R[j];
            j++;
            count++;//global variables
        }
    }
}
void MergeSort(int *A, int left, int right)
{
    int mid;
    if(left + 1 < right){
        mid = (left +right) / 2;
        //left side [left,mid)
        MergeSort(A,left,mid);
        //right side [mid,right)
        MergeSort(A,mid,right);
        Merge(A,left,mid,right);
    }
}
int main()
{
    int i;
    int n,mid,left,right;
    int *A;//the array for a sequence of values;
    //the length of a sequence of values
    scanf("%d",&n);
    left = 0;
    right = n;
    A = (int *)malloc(sizeof(int) * n);
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&A[i]);
    }
    MergeSort(A,left,right);

    //print
    for(i = 0 ; i < n ; i++)
    {
        printf("%d",A[i]);
        if(i+1 < n)printf(" ");
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}