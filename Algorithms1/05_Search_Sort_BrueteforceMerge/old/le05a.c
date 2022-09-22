#include <stdio.h>
#include <stdlib.h>

int n; // the number of first sequence
int *arry;
int q; // the number of second sequence
int *questArry;

//総当たり再起Function
int solve(int i,int m)
{
    int res;
    if(m == 0){
        return 1;
    }
    //if m ≠ 0 && i >= nのときは組み合わせがなかったとして０を返す
    if( i >= n){
        return 0;
    }
    //総当たり作成どれか一つでもTrueの値ならresはtrueとなり組み合わせがあるということになる
    res = solve(i + 1, m) || solve(i + 1, m - arry[i]);
    return res;
}

int* InputNum(int *num)
{
    int i;
    int *A;
    scanf("%d", num);
    A = (int *)malloc(sizeof(int) * (*num));
    for(i = 0 ; i < (*num) ; i++)
    {
        scanf("%d", &A[i]);
    }
    return A;
}

void PrintAnswer()
{
    int i,j;
    int tmp= 0;
    //loop question's times
    
    for(i = 0 ; i < q ; i++)
    {
        if(solve(0,questArry[i]))printf("yes\n");
        else printf("no\n");
    }
}
int main()
{
    //prepareing
    arry = InputNum(&n);
    //input question sequence
    questArry = InputNum(&q);
    PrintAnswer();
    return 0;
}

