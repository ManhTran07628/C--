#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 10;
vector<int> dx{-2,-2,2,2};
vector<int> dy{-2,2,-2,2};
char a[MM][MM];
int steps[MM][MM];
vector<char> chess{'W','B'};
void bfs(int x,int y,char p)
{
    a[x][y] = '.';
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        pair<int,int> coord = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X = coord.fi + dx[i];
            int Y = coord.se + dy[i];
            if(X >= 1 && X <= 8 && Y >= 1 && Y <= 8) 
                if(a[X][Y] == 'X' || a[X][Y] == p) {
                    steps[X][Y] = steps[coord.fi][coord.se]+1;
                    q.push({X,Y});
                    a[X][Y] = '.';
                }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y,tx,ty; // 0 - black    1 - white
    cin >> x >> y >> tx >> ty;
    for(int i = 1;i <= 8;i++) {
        for(int j = 1;j <= 8;j++) {
            int s = i+j;
            if(s % 2) a[i][j] = 'B';
            else a[i][j] = 'W';
            steps[i][j] = LLONG_MAX;
        }
    }
    a[x][y] = 'C';
    a[tx][ty] = 'X';
    steps[x][y] = 0;
    bfs(x,y,chess[(tx+ty)%2]);
    cout << (steps[tx][ty] != LLONG_MAX ? steps[tx][ty] : -1);
    return 0;
}