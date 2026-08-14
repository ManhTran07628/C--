#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e6 + 7;
int n,m;
int adj[19],g[MM],f[MM];

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
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v; u--; v--;
        adj[u] = (adj[u] | (1 << v));
        adj[v] = (adj[v] | (1 << u));
    }


    g[0] = 1;
    for(int i = 0;i < n;i++)
        g[1 << i] = 1;

    for(int S = 0;S < (1 << n);S++) {
        for(int u = 0;u < n;u++) {
            if(S >> u & 1) {
                int S_ = S ^ (1 << u);
                int nxt = (g[S_] && ((S_ & adj[u]) == S_));
                g[S] = max(g[S],nxt);
            }
        }
    }

    for(int s = 0;s < (1 << n);s++) f[s] = oo;
    f[0] = 0;
    for(int S = 0;S < (1 << n);S++) {
        if(g[S] == 1) f[S] = 1;
        for(int t = S;t;t = (t - 1) & S)
            f[S] = min(f[S],f[t] + f[S ^ t]);
    }

    

    // cout << 1235 << ' ' << (1235 & (-1235));

    cout << f[(1 << n) - 1];

    return 0;
}