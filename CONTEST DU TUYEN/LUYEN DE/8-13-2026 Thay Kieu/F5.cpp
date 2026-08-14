#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;
vector<int> adj[MM];

namespace brute
{
    int cnt[MM];
    void solve()
    {
        int res = 0;
        for(int i = 1;i <= n;i++) { // u v s
            int u = i;

            int j = upper_bound(adj[u].begin(),adj[u].end(),u) - adj[u].begin();
            for(;j < adj[u].size();j++) {
                int v = adj[u][j];
                if(v <= u) continue;

                int k = upper_bound(adj[v].begin(),adj[v].end(),v) - adj[v].begin();
                for(int k = 0;k < adj[v].size();k++) {
                    int s = adj[v][k];

                    if(s <= v) continue;

                    
                    int pos = lower_bound(adj[s].begin(),adj[s].end(),u) - adj[s].begin();
                    if(adj[s][pos] == u) {
                        res++;
                        // cout << u << ' ' << v << ' ' << s << '\n';
                        cnt[u]++;
                        cnt[v]++;
                        cnt[s]++;
                    }

                }
            }
        }
        cout << res << '\n';
        for(int i = 1;i <= n;i++) cout << cnt[i] << ' ';
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
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        sort(adj[i].begin(),adj[i].end());
    }
    brute::solve();
    return 0;
}