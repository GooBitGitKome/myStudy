#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *H;
    int n;
    int k_p,k_l,k_r;
    scanf("%d", &n);
    H = (int *)malloc(sizeof(int) * n);
    for(int j = 0 ; j < n ; j++)
    {
        //input values
        scanf("%d", &H[j]);
    }
    for(int i = 0; i < n; i++)
    {
        //親子関係を示す配列のインデックスの求め方
        //0オリジンと1オリジンで違いがあるので参照すること
        k_p = ( i - 1 ) / 2;
        k_l = i * 2 + 1;
        k_r = i * 2 + 2;

        printf("node %d: key = %d, " ,i+1, H[i]);
        //when it is the root
        if((i+1) == 1){
            printf("left key = %d, right key = %d, \n",H[k_l],H[k_r]);
            continue;
        }

        if(k_p < n){
            printf("parent key = %d, ",H[k_p]);
        }
        if(k_l < n){
            printf("left key = %d, ",H[k_l]);
        }
        if(k_r < n){
            printf("right key = %d, ",H[k_r]);
        }
        printf("\n");
    }

    
    return 0;
}