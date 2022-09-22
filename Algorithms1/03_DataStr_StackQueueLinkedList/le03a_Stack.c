#include <stdio.h>
#include <stdlib.h>
int top = 0;
void Calc(int *,int);
int main()
{
    char *buf;
    buf = (char*)malloc(sizeof(char) * 1000000000);
    int A[100];
    while(scanf("%s",buf) != EOF)
    {
        //in my program, only nunbers  enter into A[];
        //execute the calculation as soon as input the operation.
        //when the input is value
        if('0' <= buf[0] && buf[0] <= '9')
        {
            A[top] = atoi(buf);
            top++;
            continue;
        }

        //check value or not;
        switch(buf[0]){
            case 42:// When the operator is *
                Calc(A,42);
            break;
            case 43:// When the operator is +
                Calc(A,43);
            break;
            case 45:// When the operator is -
                Calc(A,45);
            break; 
        }
    }
    printf("%d\n",A[top - 1]);
   // free();
    return 0;
}

void Calc(int *A, int op)
{
    //top originally direct to the place to enter the input value 
    //To use the value of top, we decrees the top index;
    top--;
    switch(op){
            case 42:// When the operator is *
               A[top - 1] = A[top-1] * A[top];
            break;
            case 43:// When the operator is +
                A[top- 1] = A[top-1] + A[top];       
            break;
            case 45:// When the operator is -
                A[top - 1] = A[top-1] - A[top];       
            break; 
    }
}

