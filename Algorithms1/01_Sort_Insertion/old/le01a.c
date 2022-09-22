#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000000
int main() 
{
    int *nm;
    int i,j,k,wnm,key;
    int cnt=0;
    scanf(" %d",&wnm);
    nm = (int *)malloc(sizeof(int) * wnm);
    //
    if(wnm == 1){
        scanf("%d",&nm[0]);
        printf("%d\n",nm[0]);
        return 0;
    }else if(wnm == 0 )return 0;

    for(i = 0 ; i < wnm ; i++)
    {
        scanf("%d",&nm[i]);
    }

    for(k = 0 ; k < wnm; k++)
    {
        printf("%d", nm[k]);
        if(k + 1 != wnm )printf(" ");
    }
    printf("\n");

    for(i = 1 ; i < wnm; i++)
    {
        key = nm[i];
        j = i - 1;
        while(j >= 0 && nm[j] > key)
        {
            nm[j+1] = nm[j];
            j = j-1;
            
        }
        nm[j+1] =key;
        for(k = 0 ; k < wnm; k++)
        {
            printf("%d", nm[k]);
            if(k + 1 != wnm )printf(" ");
        }
        printf("\n");
    }

    return 0;
}