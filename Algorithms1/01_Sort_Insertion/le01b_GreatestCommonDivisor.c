#include <stdio.h>
int greatestCommonDivisor(int ,int);


int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n", greatestCommonDivisor(a,b));
    return 0;
}

int greatestCommonDivisor(int a, int b)
{
    if(b == 0)return a;
    return greatestCommonDivisor(b, a % b);
}

