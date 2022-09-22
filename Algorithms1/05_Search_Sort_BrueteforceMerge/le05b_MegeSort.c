#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Structure
//Prototype Declaration
void MergeSort(int l,int r);
void Merge(int l ,int mid,int r);
//Global Variables
int *A;
int cnt = 0;//count the number of conquers
int main()
{
    int n,tmp;
    scanf("%d",&n);
    A = (int *)malloc(sizeof(int) * n);
    //A[n] = INT_MAX; //sentinel
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &tmp);
        A[i] = tmp;
    }
    MergeSort(0,n);

    //printing--------------------------------
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d",A[i]);
        if(i +1 != n) printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);
    //printing--------------------------------

    return 0;
}

void MergeSort(int l,int r)
{
    if(l+1 < r){
        //calc mid index
        int mid = (l + r) / 2;
        MergeSort(l,mid);//Divide left side
        MergeSort(mid,r);//Divide right side
        Merge(l,mid,r);
    }
}

void Merge(int l ,int mid,int r)
{
    //initializing-----------------------------------------
    int n1 = mid - l;//loop times calc on left side
    int n2 = r - mid;//calc loop times on right side
    //make the both side of right side and left side array
    int *L = (int *)malloc(sizeof(int) * n1 + 1);
    int *R = (int *)malloc(sizeof(int) * n2 + 1);
    for(int i = 0; i < n1 ; i++)L[i] = A[l+i];
    for(int i = 0; i < n2 ; i++)R[i] = A[mid+i];
    L[n1] = R[n2] = INT_MAX; //sentinel
    //initializing-----------------------------------------
    int i = 0,j = 0;
    //merge
    for(int k = l ; k < r; k++)
    {

        cnt++;
        if(L[i] <= R[j])
        {
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
    free(L);
    free(R);
}