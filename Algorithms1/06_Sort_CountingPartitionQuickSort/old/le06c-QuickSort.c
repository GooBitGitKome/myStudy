// Quicksort(A, p, r)
// 1 if p < r
// 2    then q = Partition(A, p, r)
// 3        run Quicksort(A, p, q-1)
// 4        run Quicksort(A, q+1, r)
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int value;
    char letter;
    //the number of the order of Inputs. It is used to compare with the same value whether these number is exchanged, it means un stable sort;
    int inptIndx;
}DATA;

int Partition(DATA*,int p,int r);
void QuickSort(DATA*,int p,int r);
void Display(DATA* A,int n);

int main()
{
    int n;
    int dummy;
    char dummc;
    DATA *A;
    int sepIndex;//separator's index
    // take the input number of the length of the next input Array
    scanf("%d", &n);
    scanf("%c%d",&dummc,&dummy);
    //make the array having the length of [n]
    A = (DATA * )malloc(sizeof(DATA) * n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%c %d", &A[i].letter, &A[i].value);
        A[i].inptIndx = i;
        scanf("%c%d",&dummc,&dummy);
    }
    QuickSort(A,0,n-1);
    
    Display(A,n);
    
    return 0;
}

//p = leftside index , r = right index, caution: r is not [p,r) but [p,r]
int Partition(DATA* A,int l,int r)
{
    int x = A[r].value;// pivot
    DATA tmp;
    int s = l -1;
    for(int i = l ; i < r; i++)
    {
        if(A[i].value <= x){
            s++;
            tmp = A[s];
            A[s] = A[i];
            A[i] = tmp;
        }
    }
    s++;
    tmp = A[s];
    A[s] = A[r];
    A[r] = tmp;
    //return the value of separator
    return s;
}
//p = leftside index , r = right index, caution: r and new pivot q is not [p,r) but [p,r]
void QuickSort(DATA* A,int p,int r)
{
    int q;//new pivot
    if(p < r){
        q = Partition(A,p,r);
        QuickSort(A,p,q-1);//left side
        QuickSort(A,q,r);//right side
    }
}

void Display(DATA* A,int n)
{
    int tmpnum;
    int stblFlg = 0;// check whether this sort is stable or not.

    //check the sort is stable or not
    for(int i = 1 ; i < n ; i++)
    {
        if(A[i].value == A[i-1].value && A[i].inptIndx <= A[i-1].inptIndx){stblFlg++; break;}
    }
    if(stblFlg != 0){
        printf("Not stable\n");
    }else{
        printf("Stable\n");
    }
    //----------------------------

    //display
    for(int i = 0; i < n ; i++)
    {
        printf("%c %d\n", A[i].letter,A[i].value);
        // if(i+1 != n)printf("\n");
    }
}