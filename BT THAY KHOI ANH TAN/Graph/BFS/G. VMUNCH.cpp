#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 100+7;
char a[MM][MM];
int steps[MM][MM],visited[MM][MM],r,c;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()) {
        pair<int,int> coord = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X = coord.fi + dx[i];
            int Y = coord.se + dy[i];
            if(X >= 1 && X <= r && Y >= 1 && Y <= c) 
                if(!visited[X][Y] && (a[X][Y] == 'B' || a[X][Y] == '.')) {
                    steps[X][Y] = steps[coord.fi][coord.se]+1;
                    q.push({X,Y});
                    visited[X][Y] = 1;
                }
            
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            cin >> a[i][j];
            steps[i][j] = LLONG_MAX;
        }
    }
    steps[r][c] = 0;
    bfs(r,c);
    cout << (steps[1][1] == LLONG_MAX ? -1 : steps[1][1]);
    return 0;
}