#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n;
vector<int> adj[MM];

namespace subtask1
{
    int color[21];

    bool ok = 1;

    pii dfs(int u,int par)
    {
        int black = 0, white = 0;
        for(auto v:adj[u]) {
            if(v == par) continue;
            pii k = dfs(v,u);
            black += k.fi; 
            white += k.se;
        }
        if(color[u]) black++;
        else white++;
        if(abs(black - white) > 1) ok = 0;
        return {black,white};
    }

    void solve()
    {
        ll res = 0;
        for(int mask = 0;mask < (1 << n);mask++) {

            for(int i = 0;i < n;i++) color[i+1] = 0;
            for(int i = 0;i < n;i++) if(mask >> i & 1) color[i+1] = 1;

            ok = 1;
            dfs(1,0);
            if(ok) res++;
        }
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
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    subtask1::solve();

    return 0;
}