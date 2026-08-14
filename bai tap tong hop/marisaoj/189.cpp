#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
ll n,st[MM],en[MM],a[MM],timeDFS = 0,tour[MM],q;
vector<int> adj[MM];

void dfs(int u,int par)
{
    tour[++timeDFS] = u;
    st[u] = timeDFS;
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
        }
    }
    en[u] = timeDFS;
    // if(u != 1) {
    //     tour[++timeDFS] = par;
    //     en[par] = timeDFS;
    // }
}

struct BIT{
    vector<ll> bit;
    BIT(int n) : bit(n+1,0) {};

    void update(int u,ll val)
    {
        for(;u <= n;u += u & -u) bit[u] += val;
    }

    void updateQuery(int u,ll val)
    {
        update(st[u],val);
        update(en[u]+1,-val);
    }

    ll get(int u)
    {
        ll res = 0;
        for(;u >= 1;u -= u & -u) res += bit[u];
        return res;
    }

};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    BIT b(n+7);
    while(q--) {
        int i,x;
        cin >> i >> x;
        b.updateQuery(i,x);
    }
    for(int i = 1;i <= n;i++) {
        cout << b.get(st[i]) << ' ';
    }
    return 0;
}