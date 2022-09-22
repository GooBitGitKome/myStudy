#include <stdio.h>
#include <stdlib.h>
//Structure
//Prototype Declaration
//Global Variables
int main()
{
    int n,n_1,n_2;
    int cnt = 0;
    int *S,*T;
    scanf("%d",&n);
    n_1 = n;
    S = (int*)malloc(sizeof(int) * n+1);
    //Make matrix S
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&S[i]);
    }

    scanf("%d",&n);
    n_2 = n;
    T = (int*)malloc(sizeof(int) * n+1);
    //Make matrix T
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&T[i]);
    }

    for(int i = 0 ; i < n_2 ; i++)
    {
        S[n_1] = T[i];
        for(int j = 0 ; j < n_1; j++)
        {
            if(S[j] == S[n_1]){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}