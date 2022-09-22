#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 3
#define N2 9

struct Puzzle{
    int f[N2];
    int space;
    string path;
    bool operator < (const Puzzle &p) const{
        for(int i = 0; i < N2; i++)
        {
            if(f[i] == p.f[i])continue;
            return f[i] > p.f[i];// new element meant
        }
        return false;// new element meant
    }
};

static const int dx[4] = {-1,0,1,0};//movement of space x
static const int dy[4] = {0,-1,0,1};//movement of space y
static const char dir[4] = {'u','l','d','r'};

bool isTarget(Puzzle p)
{
    for(int i = 0; i < N2; i++)
    {
        //this puzzle is completed or not
        if(p.f[i] != (i + 1)) return false;
    }
    return true;//puzzle completed
}

string bfs(Puzzle s)
{
    queue<Puzzle> Q;
    map<Puzzle, bool> V;//whether it was already checked
    Puzzle u,v;
    s.path="";
    Q.push(s);
    V[s]=true;//what?

    while(!Q.empty()){
        u= Q.front(); Q.pop();
        if(isTarget(u))return u.path;    
        //it is based on the graph of the up left origine
        int sx = u.space % N;// x position as graph
        int sy = u.space / N;// y position as graph
        for(int r = 0; r < 4 ; r++)//transfer the space plate
        {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if(tx<0||ty<0||tx>=N||ty>=N) continue;
            v=u;//v becomes the key of map list
            swap(v.f[u.space],v.f[tx + ty*N]);
            v.space = tx + ty*N;
            if(!V[v])//check this map is already checked or not
            {
                V[v] = true;//mark as checked
                v.path += dir[r];//record the movement charactor
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}
int main()
{
    Puzzle in;
    for(int i = 0; i < N2; i++)
    {
        cin >> in.f[i];
        if(in.f[i] == 0)//space
        {
            in.f[i] = N2;
            in.space = i;//space index
        }
    }
    string ans = bfs(in);
    cout << ans.size() <<endl;

    return 0;
}
