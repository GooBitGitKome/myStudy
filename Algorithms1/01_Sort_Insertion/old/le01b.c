#include <stdio.h>

int main()
{
    int a,b,r,tmp;
    scanf("%d %d", &a,&b);
    if(a < b){
        tmp = b;
        b = a;
        a = tmp;
    }else if(a == b){printf("%d\n",b);return 0;}
    
    for(; b != 0;){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    printf("%d\n",a);

    return 0;
}