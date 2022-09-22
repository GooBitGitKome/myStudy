#include <stdio.h>
#include <stdlib.h>
//Structure
//Prototype Declaration
int BinarySearch(int*,int,int);
//Global Variables
int main()
{
    int n,n_S,n_T;
    int cnt=0;
    int *S,*T;
    //make the matrix S
    scanf("%d",&n_S);
    S = (int*)malloc(sizeof(int) * n_S);
    for(int i = 0 ; i < n_S ; i++)
    {
        scanf("%d",&S[i]);
    }

    //make the matrix T
    scanf("%d",&n_T);
    T = (int*)malloc(sizeof(int) * n_T);
    for(int i = 0 ; i < n_T ; i++)
    {
        scanf("%d",&T[i]);
        //binary search():found 1 , not found 0
        cnt += BinarySearch(S,T[i],n_S);
    }
    printf("%d\n", cnt);
    return 0;
}

int BinarySearch(int *S,int key, int n)
{
    //Binary Search [l,r)
    int l,r,mid;
    l = 0;
    r = n;
    while(l < r)
    {
        mid = (r + l) / 2;
        if(S[mid] == key)return 1;
        else if(key < S[mid])r = mid;
        else l = mid + 1;       
    }
    return 0;
}