#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 100 + 7;
string a[3];
int n,vis[3][MM];
vector<int> dx{1,0,1,-1};
vector<int> dy{0,1,1,1};

bool check(int X,int Y)
{
    return (1 <= X && X <= 2 && 1 <= Y && Y <= n);
}

void dfs(int x,int y)
{
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++) {
        int u = x + dx[i], v = y + dy[i];
        if(check(u,v) && a[u][v] == '0' && !vis[u][v]) {
            dfs(u,v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= 2;i++) {
            cin >> a[i];
            a[i] = ' ' + a[i];
        }
        for(int i = 1;i <= 2;i++) {
            if(a[i][1] == '0') dfs(i,1);
        }
        if(vis[2][n]) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        for(int i = 1;i <= 2;i++)
            fill(vis[i]+1,vis[i]+n+1,0);
    }
    return 0;
}