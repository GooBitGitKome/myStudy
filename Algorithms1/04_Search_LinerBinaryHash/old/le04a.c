//liner search
#include <stdio.h>
#include <stdlib.h>

void getNum(int *, int);
int  linearSearch(int *A,int n,int key);
int main()
{
    int n;// n ≤ 10000
    int q;// q ≤ 500
    int *S;// 0 ≤ an element in S ≤ 10^9
    int *T;// 0 ≤ an element in T ≤ 10^9
    int i,j;//loop counters
    int key;
    int searchCnt = 0;//Count discovered num 
    scanf("%d",&n);
    if(n > 10000)fprintf(stderr,"error\n");
    S = (int *)malloc(sizeof(int)*n +1);
    getNum(S,n);    

    scanf("%d",&q);
    if(q > 500)fprintf(stderr,"error\n");
    T = (int *)malloc(sizeof(int)*q);  
    getNum(T,q);

    
    for(j = 0 ; j < q ; j++)
    {
        //when discorevering the num,
        if(linearSearch(S,n,T[j]) >= 0)searchCnt++;
    }

    printf("%d\n",searchCnt);

    free(S);
    free(T);
    return 0;
}

void getNum(int *A, int num)
{
    int i; //loop counter
    for(i = 0 ; i< num ; i ++){
        scanf("%d",&A[i]);
    }

}

int  linearSearch(int *A,int n,int key)
{
    int i = 0;
    A[n] = key;
    while(A[i] != A[n])
    {
        i++;
    }
    if(i == n)return -1;
    return i;
}