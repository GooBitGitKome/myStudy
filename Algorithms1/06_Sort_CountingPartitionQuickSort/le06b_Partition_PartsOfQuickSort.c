#include <stdio.h>
#include <stdlib.h>
//Prototype declaration
int Partition(int*,int p,int r);

int main()
{
    int n;
    int *A;
    int sepIndex;//separator's index
    // take the input number of the length of the next input Array
    scanf("%d", &n);
    //make the array which has the length of [n]
    A = (int * )malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++)
    {
        //input val and enter it in A[i]
        scanf("%d", &A[i]);
    }
    //Partition(Array I want to sort, leftside index, right sideindex):this function the scale is[l,r]:containing r
    //return the value of separation position in A
    sepIndex = Partition(A,0,n-1);
    
    //Display
    for(int i = 0; i < n ; i++)
    {
        if(i == sepIndex)printf("[%d]", A[i]);//print the separation point
        else printf("%d", A[i]);
        if(i+1 != n)printf(" ");
    }
    printf("\n");
    
    return 0;
}

//l = leftside index , r = right index, caution: r is not [p,r) but [p,r]
int Partition(int* A,int l,int r)
{
    //A[r] is last time pivot: So IMPORTANT point : it will cause any problem if you do not decide it properly
    int pivot = A[r];// pivot //the most right side value is used to pivot
    int tmp;//for swap
    int separator = l -1;//it will be next pivot
    //to one to the last index,(remains A[r] values)
    for(int i = l ; i < r; i++)
    {
        // compared until the last val of x:A[r]
        if(A[i] <= pivot){
            separator++;
            tmp = A[separator];
            A[separator] = A[i];
            A[i] = tmp;
        }
    }
    // Pivotを基準にセパレーターのインデックスで分けてきた。
    // 最後にセパレーターのインデックスの位置でPivotとlast value をスワップし、整列を完了とする
    separator++;
    tmp = A[separator];
    A[separator] = A[r];
    A[r] = tmp;
    //return the value of separator
    //it will be the next time PIVOT
    return separator;
}