#include <stdio.h>
#include <stdlib.h>
#define PRINT printf("Test\n");
int main()
{
    int i,j,inSequence,tmp,cnt=0;
    int *array;

    scanf("%d", &inSequence);
    array = (int *)malloc(sizeof(int) * inSequence);

    i=0;
    while(i < inSequence)
    {
        scanf("%d", &array[i]);
        i++;
    }

    for(i = 0 ; i < inSequence-1 ; i++)
    {
        
        for(j = inSequence - 1 ; j >= i + 1; j--)
        {
            if(array[j-1] > array[j])
            {
                cnt++;
                tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
            }
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