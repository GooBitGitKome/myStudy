#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int judgePrime(int);
int main()
{
    //素数判定
    // 与えられた数字Nに対して、約数を考えた場合の組み合わせはroot(N)^2を超えることはない。
    // 今回の場合は組み合わせ公約数が1のみであればいいので、公約数がなければそれは素数であるという方向
    // でプログラムを作成する。
    int list_nm;
    int val,cnt = 0;
    scanf("%d", &list_nm);
    
    for(int i = 0; i < list_nm; i++)
    {
        scanf("%d",&val);
        if(judgePrime(val) != 0)cnt++;
    }
    printf("%d\n",cnt);
    
    return 0;
}

int judgePrime(int val)
{
    //Judge prime number
    for(int i = 2; i <= sqrt(val); i++)
    {
        //not prime
        if(val % i == 0)return 0;
        
    }
    // this value is prime
    return 1;
}