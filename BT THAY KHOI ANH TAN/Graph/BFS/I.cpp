#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1007;
vector<int> dx{-2,-1,1,2,2,1,-1,-2};
vector<int> dy{1,2,2,1,-1,-2,-2,-1};
char a[MM][MM];
int steps[MM][MM],n,m,X1,Y1,X2,Y2;
void bfs(int x,int y)
{
    a[x][y] = '#';
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        pair<int,int> coord = q.front();
        q.pop();
        for(int i = 0;i < 8;i++) {
            int X = coord.fi + dx[i];
            int Y = coord.se + dy[i];
            if(X >= 1 && X <= n && Y >= 1 && Y <= m) 
                if(a[X][Y] == '.') {
                    steps[X][Y] = steps[coord.fi][coord.se]+1;
                    q.push({X,Y});
                    a[X][Y] = '#';
                }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> X1 >> Y1 >> X2 >> Y2;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            a[i][j] = '.';
            steps[i][j] = LLONG_MAX;
        }
    }
    steps[X1][Y1] = 0;
    bfs(X1,Y1);
    cout << (steps[X2][Y2] != LLONG_MAX ? steps[X2][Y2] : -1);
    return 0;
}