#include <stdio.h>
#include <stdlib.h>
//Structure
//Prototype Declaration
//Global Variables
int main()
{
    int n,degree,buff,v;
    int **G;
    scanf("%d",&n);
    G = (int**)malloc(sizeof(int*) * n+1);
    //create n * n matrix G
    for(int i = 0 ; i <= n ; i++)
    {
        G[i] = (int *)malloc(sizeof(int) * n+1);
    }

    for(int i = 0 ; i < n ; i++)
    {
        //input the vertex
        scanf("%d",&v);
        //input degree and loop based on the degree
        scanf("%d",&degree);
        for(int j = 0 ; j < degree ; j++)
        {
            //make the relation ship each node havs
            scanf("%d",&buff);
            G[v][buff] = 1;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            printf("%d", G[i][j]);
            if(j != n)printf(" ");
        }
        printf("\n");
    }

    return 0;
}