#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1000+7;
int n,m,a[MM][MM],visited[MM][MM][4];
int xd,yd,cost[MM][MM][4];
vector<int> dx{-1,0,1,0};
vector<int> dy{0,-1,0,1}; // U L D R



bool check(int x,int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}


void bfs()
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = 0;k < 4;k++)
                cost[i][j][k] = oo;
        }
    }
    queue<pair<pair<int,int>,int>> q;
    cost[1][1][2] = 1;
    cost[1][1][3] = 1;
    visited[1][1][2] = 1;
    visited[1][1][3] = 1;
    q.push({{1,1},2});
    q.push({{1,1},3});
    while(!q.empty()) {
        int X1 = q.front().fi.fi,Y1 = q.front().fi.se;
        int dir = q.front().se;
        q.pop();
        // xu ly tim duong di

        int X2 = X1 + dx[dir], Y2 = Y1 + dy[dir];
        if(check(X2,Y2) && !a[X2][Y2] && !visited[X2][Y2][dir]) {
            cost[X2][Y2][dir] = cost[X1][Y1][dir]+1;
            visited[X2][Y2][dir] = 1;
            q.push({{X2,Y2},dir});
        }

        int dirn = (dir+1)%4;

        X2 = X1 + dx[dirn], Y2 = Y1 + dy[dirn];
        if(check(X2,Y2) && !a[X2][Y2] && !visited[X2][Y2][dirn]) {
            cost[X2][Y2][dirn] = cost[X1][Y1][dir]+1;
            visited[X2][Y2][dirn] = 1;
            q.push({{X2,Y2},dirn});
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
    cin >> xd >> yd;
    bfs();
    int ans = oo;
    for(int i = 0;i < 4;i++) {
        ans = min(ans,cost[xd][yd][i]);
    }
    cout << (ans != oo ? ans : 0);
    return 0;
}