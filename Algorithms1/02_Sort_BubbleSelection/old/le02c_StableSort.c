#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRINT for(int x = 0; x < in ; x++){printf("%s ",arry[x]);}printf("\n");
#define PRINT4 for(int x = 0; x < in ; x++){printf("%s ",arry2[x]);}printf("\n");
#define PRINT5 printf("%s : %s\n",arry2[min], arry2[j]);
#define PRINT2 printf("test\n");
#define PRINT3 printf("%c \n",arry[j][1]);
int main()
{
    int i,j,in;
    int min,flg=0;
    char tmp[3];
    char tmp2[3];
    char (*arry)[3];
    char (*arry2)[3];
    scanf("%d", &in);
    //ここに一番時間がかかった。
    //実体を持った２次元配列の先頭アドレスを取得する方法
    arry = (char (*)[3])malloc(sizeof(char) * 3 * in);
    arry2 = (char (*)[3])malloc(sizeof(char) * 3 * in);

    for(i = 0 ; i < in ; i++)
    {
        scanf("%s", arry[i]);
        strcpy(arry2[i],arry[i]);
    }

    //Bubble sort
    for(i = 0 ; i < in ; i++)
    {
        //min = atoi(arry[i][0]);
        for(j = in - 1 ; j >= i + 1 ; j--)
        {
            //compare those values by ASCII-code
            if(arry[j][1] < arry[j-1][1]){
                strcpy(tmp, arry[j]);
                strcpy(arry[j],arry[j-1]);
                strcpy(arry[j-1],tmp);
            }
        }
    }
 //Selection sort
    for(i = 0 ; i < in - 1 ; i++)
    {
        min = i;
        for(j = i; j < in ; j++)
        {
            if(arry2[min][1] > arry2[j][1]){
                min = j;
            }
        }
        strcpy(tmp ,  arry2[min]);  
        strcpy(tmp2, arry2[i]);      
        strcpy(arry2[i] , tmp);
        strcpy(arry2[min], tmp2);
        //下記の書き方ではIlligation error４のようなエラーが起こる。上記のソートでは可能であったので不思議である。
        //３時間を無駄にした
    //     strcpy(tmp, arry2[i]);
    //     strcpy(arry2[i],arry2[min]);
    //     strcpy(arry2[min], tmp);

    }
    for(i = 0;  i< in ; i++)
    {
        printf("%s",arry[i]);
        if(i+1 != in)printf(" ");
    }
    printf("\nStable\n");
    for(i = 0;  i< in ; i++)
    {
        printf("%s",arry2[i]);
        if(i+1 != in)printf(" ");
        if(strcmp(arry[i],arry2[i]))flg++;
    }
    printf("\n");
    if(flg != 0 ){
        printf("Not stable");
    }else{
        printf("Stable");
    }
    printf("\n");
    return 0;
}