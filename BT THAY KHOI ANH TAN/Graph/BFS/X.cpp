#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
int a[MM][MM],cost[MM][MM][9],visited[MM][MM][9];
int n,m;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

bool check(int x,int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}

void bfs()
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = 0;k < 8;k++)
                cost[i][j][k] = oo;
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},0});
    cost[1][1][0] = 1;
    while(!q.empty()) {
        int X1 = q.front().fi.fi, Y1 = q.front().fi.se;
        int dir = q.front().se;
        q.pop();
        for(int i = 0;i < 8;i++) {
            if(i == dir) continue;
            int steps = a[X1][Y1];
            int X2 = X1 + dx[i]*steps,Y2 = Y1 + dy[i]*steps;
            if(check(X2,Y2) && cost[X2][Y2][i] > cost[X1][Y1][dir]+1) {
                cost[X2][Y2][i] = cost[X1][Y1][dir]+1;
                q.push({{X2,Y2},i});
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    bfs();
    int ans = oo;
    for(int i = 0;i < 8;i++) {
        ans = min(ans,cost[n][m][i]);
    }
    cout << (ans != oo ? ans : -1);
    return 0;
}