#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//Macros
#define MAX 1001
//Structures
//Prototype Declarations
int LCS(char X[MAX], char Y[MAX]);
//Global Variables
int main()
{
    int n;
    char s1[MAX],s2[MAX];//each is X, Y;
    scanf("%d",&n);//n * 2 times, there are inputs as the set of X and Y
    for(int i = 0 ; i < n ; i++)
    {
        s1[0] = ' ';//the head of array is NULL
        s2[0] = ' ';//and loop index will start from 1 for this array
        scanf("%s%s", s1+1,s2+1);
        printf("%d\n", LCS(s1,s2));
    }
    return 0;
}

int LCS(char X[MAX], char Y[MAX])
{
    //initializing-----------------------------------------
    int maxl = 0;
    int x_l,y_l;
    x_l = strlen(X);//this contains NULL character
    y_l = strlen(Y);
    int c[MAX][MAX];//array for the longest string
    for(int i = 0; i <= x_l; i++)c[0][i] = 0;//the top of array is used to be NULL
    for(int i = 0 ; i <= y_l; i++)c[i][0] = 0;
    //initializing-----------------------------------------
    for(int j = 1; j < y_l; j++)
    {
        for(int i = 1; i <x_l; i++)
        {
            if(X[i] == Y[j])
            {
                //printf("%c %c \n",X[i], Y[j]);
                c[j][i] = c[j-1][i-1] + 1;
            }else{
                c[j][i] = c[j-1][i] > c[j][i -1]?  c[j-1][i] : c[j][i -1];
            }
            maxl = maxl > c[j][i]? maxl : c[j][i]; 
        }
    }


    return maxl;
}