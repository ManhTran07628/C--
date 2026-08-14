#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e3;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};
int h[MM][MM],n,visited[MM][MM];

bool bfs(int x,int y,int l,int r)
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            visited[i][j] = 0;
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    if ((l > h[x][y]) || (h[x][y] > r)) return 0;
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X = u.fi + dx[i];
            int Y = u.se + dy[i];
            if(X >= 1 && Y >= 1 && X <= n && Y <= n && !visited[X][Y]) {
                if(l <= h[X][Y] && h[X][Y] <= r) {
                    visited[X][Y] = 1;
                    q.push({X,Y});
                }
            }
        }
    }
    return visited[n][n];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> h[i][j];
        }
    }
    int ans = LLONG_MAX;
    for(int i = 0;i <= 100;i++) {
        for(int j = 0;j <= 100;j++) {
            if(bfs(1,1,i,j)) {
                ans = min(ans,abs(j-i));
            }
        }
    }
    cout << ans;
    return 0;
}