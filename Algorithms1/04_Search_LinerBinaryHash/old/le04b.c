#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *A,int n,int key);
void getNum(int *, int);

int main()
{
    int n;// n ≤ 1000000
    int q;// q ≤ 50000
    int *S;// 0 ≤ an element in S ≤ 10^9
    int *T;// 0 ≤ an element in T ≤ 10^9
    int i,j;//loop counters
    int key;
    int searchCnt = 0;//Count discovered num 
    scanf("%d",&n);
    if(n > 1000000)fprintf(stderr,"error\n");
    S = (int *)malloc(sizeof(int)*n );
    getNum(S,n);    

    scanf("%d",&q);
    if(q > 50000)fprintf(stderr,"error\n");
    T = (int *)malloc(sizeof(int)*q);  
    getNum(T,q);

    
    for(j = 0 ; j < q ; j++)
    {
        //when discorevering the num,
        if(binarySearch(S,n,T[j]) >= 0)searchCnt++;
    }

    printf("%d\n",searchCnt);

    free(S);
    free(T);
    return 0;
}

int binarySearch(int *A,int n,int key)
{
    int left = 0;
    int right = n;
    int mid;
    while (left < right){
        mid = (left + right) / 2;
        if(A[mid] == key)
            return mid;
        else if(key < A[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

void getNum(int *A, int num)
{
    int i; //loop counter
    for(i = 0 ; i< num ; i ++){
        scanf("%d",&A[i]);
    }

}