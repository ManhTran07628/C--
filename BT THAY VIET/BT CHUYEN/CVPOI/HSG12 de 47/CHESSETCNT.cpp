#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
ll n,m;
vector<pair<int,int>> bad;

namespace subtask1
{
    int vis[10][10];
    ll res = 0;
    void Try(int x,int y)
    {
        if(y > m) {
            x++;
            y = 1;
        }
        if(x > m) {
            res++; res %= MOD;
            return;
        }
        bool ok = 1;
        for(auto C:bad) {
            for(int i = 1;i <= C.fi;i++)
                for(int j = 1;j <= C.se;j++)
                    if(x <= C.fi && y <= C.se && vis[i][j]) {
                        ok = 0;
                        break;
                    } 
        }

        if(ok) {
            vis[x][y] = 1;
            Try(x,y+1);
            vis[x][y] = 0;
        }
        Try(x,y+1);

    }
    
    void solve()
    {
        Try(1,1);
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        int u,v; cin >> u >> v;
        bad.push_back({u,v});
    }
    if(n <= 10 && m <= 5) subtask1::solve();
    else subtask2::solve();
    // subtask1::solve(); cout << '\n';
    // subtask2::solve();
    // subtask2::solve();
    return 0;
}