#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define WALKED 1000
#define WALL 49
#define START 115 // ASCII s
#define GOAL 103 // ASCII g
int W = 0;//set maze width
int H = 0;//set maze height
int N2 =0;//put  W * H;
struct Puzzle{
    int f[MAX];
    int space;
    int cnt;
    string path;
    bool operator < (const Puzzle &p) const{
        for(int i = 0; i < N2; i++)
        {
            if(f[i] == p.f[i])
            {
                continue;
            }

            return f[i] > p.f[i];// new element meant
        }
        return false;// new element meant
    }
};

static const int dx[4] = {-1,0,1,0};//movement of space x
static const int dy[4] = {0,-1,0,1};//movement of space y
static const char dir[4] = {'l','d','r','u'};

bool isTarget(Puzzle p)
{
    // for(int i = 0; i < N2; i++)
    // {
    //     //this puzzle is completed or not
    //     if(p.f[i] != (i + 1)) return false;
    // }
    return p.f[p.space] == GOAL ? true : false;//puzzle completed
}

int bfs(Puzzle s)
{
    queue<Puzzle> Q;
    string tmp_ans = "0000000000000000000000000000000";
    map<Puzzle, bool> V;//whether it was already checked
    Puzzle u,v;
    s.path="";
    s.cnt = 1;
    Q.push(s);
    V[s]=true;//already checked bool

    while(!Q.empty()){
        u= Q.front(); Q.pop();
        if(isTarget(u)){return u.cnt;}
        //it is based on the graph of the up left origine
        int sx = u.space % W;// x position as graph
        int sy = u.space / W;// y position as graph
        for(int r = 0; r < 4 ; r++)//transfer the space plate
        {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if(tx<0||ty<0||tx>=W||ty>=H) continue;//out of the range
            if(u.f[tx + ty*W] == WALL || u.f[tx + ty*W] == WALKED)continue;//the planned place is wall
            v=u;//v becomes the key of map list
            // swap(v.f[u.space],v.f[tx + ty*W]);//new map created
            v.space = tx + ty*W;//1dimention expression and new start point
            v.path += dir[r];//record the movement charactor
            if(isTarget(v)){return v.cnt;}
            else v.f[v.space] = WALKED;

            if(!V[v])//check this map is already checked or not
            {
                v.cnt++;
                V[v] = true;//mark as checked
                v.path += dir[r];//record the movement charactor
                Q.push(v);
            }
        }
    }
    return 1;
}
int main()
{
    scanf("%d%d", &W, &H);//set width and height
    Puzzle in;
    N2 = W * H;
    for(int i = 0; i < N2; i++)
    {
        char s[2];
        cin >> s;
        in.f[i] = (int)s[0];
        if(in.f[i] == START)//space
        {
            in.f[i] = WALKED;
            in.space = i;//space index
        }
    }
    int ans = bfs(in);
    if(ans ==1)cout << "Fail" << endl;
    else cout << ans <<endl;

    return 0;
}
