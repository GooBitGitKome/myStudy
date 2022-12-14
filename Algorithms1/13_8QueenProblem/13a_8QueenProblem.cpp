#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define NOT_FREE 1
#define FREE -1
#define MAX 10001
#define N 8
int col[N] = {0};
int row[N];
int dpos[2*N -1];
int dneg[2*N -1];
bool X[N][N];
void Initialize()
{
    for(int i = 0 ; i < N ; i++){row[i] = col[i] = FREE;}
    for(int i = 0 ; i < 2 * N -1 ; i++){dpos[i] = dneg[i] = FREE;}
}
void PrintBoard()
{
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            if(X[i][j])
            {
                if(row[i] != j) return;
            }
        }
    }
    for(int i = 0 ; i < N ; i++)
    {
        for(int j= 0; j < N ; j++)
        {
            cout<< ( (row[i] == j) ? "Q" : ".");
        }
        cout<<endl;
    }
}
void RecursivePutQueen(int i)
{
    if( i == N)
    {
        PrintBoard();
        return;
    }
    for(int j = 0; j < N ; j++)
    {
        if(col[j] == NOT_FREE || dpos[i+j] == NOT_FREE || dneg[i - j + N - 1] == NOT_FREE)
        {continue;}
        //put a queen at (i,j)
        row[i] = j;
        col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
        //try the next row
        RecursivePutQueen(i+1);
        //remove the queen at(i,j) fro backtracking
        row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
    }
}
class MyClass
{
public:
    //Strurecures
    //Prototype Declarations
    //Global Variables
    //function------------------------------------------------------------------------
};
int main()
{
    int n;
    scanf("%d",&n);
    int r,c;
    Initialize();
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d%d", &r ,&c);
        X[r][c] = true;
        // col[r] = NOT_FREE;
        // row[N-c] = NOT_FREE;
    }
    RecursivePutQueen(0);
    return 0;
}