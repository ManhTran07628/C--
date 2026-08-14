#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e9
#define pii pair<int,int>
const int MM = 500+7;
int n,a[MM][MM],d[MM][MM];
vector<pii> safe;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool valid(int x,int y)
{
    return (1 <= x && x < MM && 1 <= y && y < MM);
}

void bfs()
{
    queue<pii> q;
    for(int i = 1;i < MM;i++)
        for(int j = 1;j < MM;j++)
            d[i][j] = oo;

    d[1][1] = 0;
    q.push({1,1});
    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        if(d[x][y] >= a[x][y]) continue;
        for(int i = 0;i < 4;i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            if(valid(u,v) && d[u][v] > d[x][y] + 1 && d[x][y] + 1 < a[u][v] ) {
                d[u][v] = d[x][y] + 1;
                q.push({u,v});
             }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 1;i < MM;i++)
        for(int j = 1;j < MM;j++)
            a[i][j] = oo;

    for(int i = 1;i <= n;i++) {
        int x,y,t;
        cin >> x >> y >> t; x++; y++;
        a[x][y] = min(a[x][y],t);
        a[x-1][y] = min(a[x-1][y],t);
        a[x+1][y] = min(a[x+1][y],t);
        a[x][y-1] = min(a[x][y-1],t);
        a[x][y+1] = min(a[x][y+1],t);
    }

    for(int i = 1;i < MM;i++)
        for(int j = 1;j < MM;j++)
            if(a[i][j] == oo)
                safe.push_back({i,j});

    // for(int i = 1;i <= 7;i++) {
    //     for(int j = 1;j <= 7;j++) 
    //         cout << (a[i][j] == oo ? -1 : a[i][j]) << ' ';
    //     cout << '\n';
    // }
    
    bfs();
    // for(int i = 1;i <= 7;i++) {
    //     for(int j = 1;j <= 7;j++) 
    //         cout << d[i][j] << ' ';
    //         // cout << (a[i][j] == oo ? -1 : a[i][j]) << ' ';
    //     cout << '\n';
    // }
    int res = oo;
    for(auto U:safe) {
        int x = U.fi, y = U.se;
        if(a[x][y] == oo) {
            // cout << x << ' ' << y << '\n';
            res = min(res,d[x][y]);
        }
    }
    cout << (res == oo ? -1 : res);
    return 0;
}