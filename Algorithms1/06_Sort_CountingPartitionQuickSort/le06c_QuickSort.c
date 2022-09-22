#include <stdio.h>
#include <stdlib.h>
//Structure
typedef struct{
    int value;
    char letter;
    //the number of the order of Inputs. 
    // It is used to compare with the same value 
    // whether these number is exchanged, it means un stable sort;
    int inptIndx;
}DATA;
//Prototype Declaration
int Partition(DATA*,int l,int r);
void QuickSort(DATA*,int l,int r);
void Display(DATA* A,int n);

int main()
{
    int n;
    int dummy;
    DATA *A;
    int sepIndex;//separator's index
    // take the input number of the length of the next input Array
    scanf("%d", &n);
    scanf("%d",&dummy);//for skipping the new line or space
    //make the array having the length of [n]
    A = (DATA * )malloc(sizeof(DATA) * n);
    //input the values from user input
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%c %d", &A[i].letter, &A[i].value);
        A[i].inptIndx = i;// the order when it was inputed:in order to check whether this sort is stable or not
        scanf("%d",&dummy);//for skipping the new line or space
    }
    QuickSort(A,0,n-1);
    
    Display(A,n);
    
    return 0;
}
//p = leftside index , r = right index, caution: r and new pivot q is not [p,r) but [p,r]
void QuickSort(DATA* A,int l,int r)
{
    int newPivot;//new pivot
    if(l < r){
        newPivot = Partition(A,l,r);
        QuickSort(A,l,newPivot - 1);//left side
        QuickSort(A,newPivot + 1,r);//right side
    }
}

//p = leftside index , r = right index, caution: r is not [p,r) but [p,r]
int Partition(DATA* A,int p,int r)
{
    int x = A[r].value;// pivot
    DATA tmp;
    int s = p -1;
    for(int i = p ; i < r; i++)
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