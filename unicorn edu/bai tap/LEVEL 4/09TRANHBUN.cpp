#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 2e3+7;
const int lim = 500;
int x,y,n,forb[MM][MM],vis[MM][MM],d[MM][MM];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool valid(int x,int y)
{
    return (0 <= x && x <= 1000 && 0 <= y && y <= 1000);
}

void bfs(int x,int y)
{
    queue<pii> q;
    q.push({x,y});
    for(int i = 0;i <= 1000;i++)    
        for(int j = 0;j <= 1000;j++)
            d[i][j] = oo;
    
    d[x][y] = 0;
    while(!q.empty()) {
        pii U = q.front(); q.pop();
        int X1 = U.fi, Y1 = U.se;
        for(int i = 0;i < 4;i++) {
            int X2 = X1 + dx[i];
            int Y2 = Y1 + dy[i];
            if(valid(X2,Y2) && !forb[X2][Y2] && d[X2][Y2] > d[X1][Y1] + 1) {
                d[X2][Y2] = d[X1][Y1] + 1;
                q.push({X2,Y2});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> n;
    x += lim; y += lim;
    for(int i = 1;i <= n;i++) {
        int u,v;
        cin >> u >> v;
        u += lim; v += lim;
        forb[u][v] = 1;
    }
    bfs(500,500);
    cout << d[x][y];
    return 0;
}