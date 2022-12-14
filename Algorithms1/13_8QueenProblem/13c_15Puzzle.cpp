#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define N 4
#define N2 16
#define LIMIT 100

static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,1,0,-1};
static const char dir[4] = {'l','u','r','d'};
int MDT[N2][N2];

struct Puzzle{int f[N2], space, MD;};
Puzzle state;
int limit; // limit of depth
int path[LIMIT];

int getAIIMD(Puzzle pz)//All pieces MD, return the sum: it will be heuristic value.
{
    int sum =0;// initialize sum
    for(int i = 0; i< N2 ; i++)//check the all position of N puzzle
    {
        if(pz.f[i] == N2)continue;//except for space place
        //calc sum: M[i] is authentic position, M[j] is the piece on the position, 
        // M[i][j] is the distance i position to j position where j should be
        sum += MDT[i][pz.f[i] - 1];//pz.f[i] -1 means to change o origine?
    }
    return sum;
}

bool isSolved()
{
    for(int i = 0; i < N2 ; i++)if(state.f[i] != i + 1)return false;
    return true;
}
bool dfs(int depth, int prev)
{
    if(state.MD == 0)return true;//complete
    //when now state + heuristic value > limit, it is cut;
    if(depth + state.MD > limit) return false;//prune this branch
    int sx = state.space % N;// calc the x position of space as graph
    int sy = state.space / N;//calc the y position of space as graph
    Puzzle tmp;

    for(int r = 0 ; r < 4;r++)//make the moved puzzle
    {
        int tx = sx + dx[r];
        int ty = sy + dy[r];
        if(tx < 0 || ty < 0 || tx >= N || ty >= N)continue;//check it will be immovable
        if( max(prev,r) - min(prev, r) == 2)continue;//avoid from moving to the previous same place

        tmp = state;//memorize prev state;
        //calc taxi distance: if the next MDT is less than prev, the last value of state.MD will be less than prev
        state.MD -= MDT[tx + ty * N][state.f[tx + ty * N]  - 1 ];//once minus the moved position MD in the state.MD
        state.MD += MDT[sx + sy * N][state.f[tx + ty * N]  -1 ];//then add the prev position MD
        swap(state.f[tx + ty * N], state.f[sx + sy * N]);
        state.space = tx + ty * N;//assign the moved position of space as the current position;
        if(dfs(depth + 1 , r)){path[depth] = r; return true;}
        state = tmp;
    }
    return false;
}
string iterative_deepening(Puzzle in)
{
    in.MD = getAIIMD(in);//get the All pieces MD sum, memolize it to Puzzle.MD
    for(limit = in.MD; limit <= LIMIT ; limit++)//set the MD as the searching limit
    {
        state = in;//set the puzzle.in to state(which is global struct)
        if(dfs(0,-100))
        {
            string ans = "";
            for(int i = 0; i < limit; i++) ans += dir[path[i]];
            return ans;
        }
    }
    return "unsolvable";
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
    for(int i = 0; i < N2; i++)
        for(int j = 0 ; j < N2; j++)
        {
            //Taxicab distance
            // MDT[i] expresses the puzzle as 1 dimension array
            // MDT[i][j] expresses the difference between the actuall position i ,
            // and j (which is different pieace or same piace on the i position)
            //if j == i means: j is on the i position of this N puzzle(i is expressed as 1 dimension array)
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);// the difference between real position i and current j piece
            //cout << MDT[i][j] << endl;
        }
    Puzzle in;// make the input Puzzle struct
    for(int i = 0; i < N2; i++)//inpu first positions of each pieces
    {
        cin >> in.f[i];//input
        if(in.f[i] == 0)
        {
            in.f[i] = N2;//change the value 0 to N2
            in.space = i;//record the start position into space
        }
    }
    string ans = iterative_deepening(in);
    cout << ans.size() << endl;

    return 0;
}