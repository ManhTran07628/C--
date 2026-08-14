#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
ll n;
vector<int> adj[MM];


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
    ll res = n * (n - 1) * (n - 2) / 6;
    ll x = 0;
    for(int i = 1;i <= n;i++) {
        x += 1ll * adj[i].size() * adj[i].size();
    }
    res -= (1ll * (n - 1) * (n - 1) - x / 2);
    cout << res;
    return 0;
}