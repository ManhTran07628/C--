#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int n,q,st[MM],en[MM],tour[MM],timeDFS = 0;
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
}

struct BIT
{
    vector<ll> bit;
    BIT(int n) : bit(n+1) {};

    void update(int i,ll val)
    {
        for(;i <= n;i += i & -i) bit[i] += val;
    }

    ll get(int i)
    {
        ll res = 0;
        for(;i >= 1;i -= i & -i) res += bit[i];
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
    // cout << 1;
    while(q--) {
        ll t,u,v;
        cin >> t >> u;
        if(t == 1) {
            cin >> v;
            b.update(st[u],v);
            b.update(en[u]+1,-v);
        }
        else {
            cout << b.get(st[u]) << '\n';
        }
    }
    return 0;
}