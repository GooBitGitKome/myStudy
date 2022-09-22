#include <stdio.h>
#include <stdlib.h>
#define MAX_N 46
//Structure
//Prototype Declaration
int Fibonacci(int* F,int n);
//Global Variables
int main()
{
    int n;
    int F[MAX_N];
    scanf("%d",&n);
    for(int i = 0 ; i < MAX_N ; i++)
    {
        F[i] = 0;
    }
    printf("%d\n",Fibonacci(F,n));
    return 0;
}

int Fibonacci(int* F,int n)
{
    if(n == 0 || n ==1)
    {
        return F[n] = 1;//F[n]に1をメモ
    }
    if(F[n] != 0)return F[n];//F[n]が計算済みならその値を返す
    F[n] = Fibonacci(F,n-2) + Fibonacci(F,n-1);
    return F[n];
}