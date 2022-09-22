#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Structure
//Prototype Declaration
void MakeCombination();
int rec(int,int*);
//Global Variables
int *A,*M,*Ans;
int endOffArray;
int main()
{
    int n,n1,m,m1;
    scanf("%d",&endOffArray);
    A = (int *)malloc(sizeof(int) * endOffArray);
    A[endOffArray] = INT_MAX;//make stopper
    for(int i = 0 ; i < endOffArray ; i++)
    {
        scanf("%d",&n1);
        A[i] = n1;
    }
    scanf("%d",&m);
    M = (int *)malloc(sizeof(int) * m + 1);
    Ans= (int *)malloc(sizeof(int) * m + 1);
    Ans[m] = M[m] = INT_MAX;//make stopper
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d",&m1);
        M[i] = m1;
    }
    MakeCombination();
    return 0;
}

void MakeCombination()
{
    int *C = (int*)malloc(sizeof(int) * endOffArray + 1);
    C[endOffArray] = 0;
    //initializing
    for(int i = 0 ; i < endOffArray ; i++)
    {
        C[i] = 0;
    }
    rec(0,C);
    for(int i = 0 ; Ans[i] != INT_MAX ; i++)
    {
        if(Ans[i] == 1)printf("yes\n");
        else printf("no\n");
    }
}

int rec(int i,int* C)
{
    //go to the end of the array
    if(i == endOffArray){
        //Judge the A's elements adding conclude the value in M
        for(int j = 0 ; M[j] != INT_MAX; j++){
            if(M[j] == C[endOffArray])Ans[j] = 1;//Found the contination flg
        }
        return 0;
        // if(C[endOffArray] == 0)printf("yes\n");
        // else printf("no\n");
    }else{
        //前組み合わせを作ると同時に、C配列末尾をAの該当の値の合計値を格納するようにし
        //計算をついでにおこなっている。
        rec(i+1,C);
        C[i] = 1;
        C[endOffArray] += A[i];
        rec(i+1,C);
        C[i] = 0;
        C[endOffArray] -= A[i];
    }
    return 0;
}