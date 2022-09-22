#include <stdio.h>
#include <stdlib.h>
#define PRINT printf("%d %d\n",array[mini] , array[j]);
int main()
{
    int i,j,inSequence,tmp,cnt=0,flg=0;
    int mini;
    int *array;

    scanf("%d", &inSequence);
    array = (int *)malloc(sizeof(int) * inSequence);

    i=0;
    while(i < inSequence)
    {
        scanf("%d", &array[i]);
        i++;
    }
    if(inSequence == 1){

    }else{
        for(i = 0 ; i < inSequence ; i++)
        {
            mini = i;
            for(j = i ; j < inSequence; j++)
            {
                if(array[j] < array[mini])
                {
                    mini = j;
                    flg=1;
                }
            }
            if(flg==1){
                cnt++;
                flg=0;    
            }
            
            tmp = array[i];
            array[i] = array[mini];
            array[mini] = tmp;
        }
    }
    

    for(i = 0 ; i < inSequence; i++)
    {
        printf("%d", array[i]);
        if(i+1 != inSequence)printf(" ");
        else printf("\n");
    }
    printf("%d\n",cnt);

    return 0;
}