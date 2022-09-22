#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void input();
int arry[100];
void calc();

int top = 1;
int main()
{
    input();
    printf("%d\n", arry[1]);
    return 0;
}

void input() 
{
    char *buff;
    buff = (char*)malloc(1000);
    while(scanf("%s", buff) != EOF)
    {
        //printf("%s\n", buff);
        if(buff[0] >= 48 && buff[0] <= 57){
            //input and store the figure 
            arry[top] = atoi(buff);
            top++;
        }else{
            // when the input value is directing the operator, move to calclation
            switch(buff[0]){
                case 42:// When the operator is *
                    calc(42);
                break;
                case 43:// When the operator is +
                    calc(43);
                break;
                case 45:// When the operator is -
                    calc(45);
                break; 
            }
        }
    }
}

void calc(int typeOfOperator)
{

    top--;
    //if stored value is only one, end the function;
    if(top - 1 == 0){
        // do nothing
    }else{

        switch(typeOfOperator){
            case 42:// When the operator is *
                arry[top-1] = arry[top -1] * arry[top];
            break;
            case 43:// When the operator is +
                arry[top-1] = arry[top -1] + arry[top];

            break;
            case 45:// When the operator is -
                arry[top-1] = arry[top -1] - arry[top];
            break;
        }
    }
}