#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char s;
    int num;
    int o;// inputede order, which is used to compare that values is correct order(Stable order);
        //if same value but the order is opposite, it means unstable sort.  
}node;
void SelectionSort(node* A,int n);
void BubbleSort(node *B,int n);
void Display(node* N,int n);
int main()
{
    int n;
    char tmp[3];//input num entered temporarily
    scanf("%d", &n);
    node *A = (node *)malloc(sizeof(node) * n + 1); //used selection sort
    node *B = (node *)malloc(sizeof(node) * n + 1); //used bubble sort
    A[n].num = B[n].num =  0;// used for counting the swap times

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s", tmp);
        A[i].s = B[i].s = tmp[0];
        A[i].num = B[i].num = (int)tmp[1] - 48;
        A[i].o = B[i].o = i;
    }
    BubbleSort(B,n);
    SelectionSort(A,n);
    Display(B,n);//Bubble sort display
    Display(A,n);//Selection sort display
    
    return 0;
}

void SelectionSort(node* A,int n)
{
    int min_index;
    node tmp;
    for(int i = 0 ; i < n ; i++)
    {
        min_index = i;
        for(int j = i;  j < n ; j++)
        {
            if(A[j].num < A[min_index].num)min_index = j;
            A[n].num++;
        }
        //structure copy
        tmp = A[min_index];
        A[min_index] = A[i];
        A[i] = tmp;
    }
}

void BubbleSort(node* B,int n)
{
    node tmp;
    for(int i = 0; i < n ; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            //swap
            if(B[j].num < B[j-1].num)
            {
                //swap structures
                tmp = B[j];
                B[j] = B[j-1];
                B[j-1] = tmp;
                B[n].num++;
            }
        }
    }
}

void Display(node *A , int n )
{
    int unstable_flg = 0;
    for(int i = 1 ; i < n; i++)
    {
        if(i == 1)printf("%c%d ",A[0].s,A[0].num);
        printf("%c%d",A[i].s,A[i].num);
        //Stable or not checking
        if(A[i-1].num == A[i].num)
        {
            //it means unstable
            if(A[i-1].o > A[i].o)unstable_flg++;
        }
        if(i+1 != n)printf(" ");
    }
    printf("\n");
    if(unstable_flg == 0){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
}