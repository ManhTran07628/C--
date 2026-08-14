#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define oo (ll) 1e18
const int MM = 3e5 + 7;
const int LOG = 17;
const int MOD = 1e9 + 7;
int t,n,a[MM],color[MM],h[MM],up[MM][LOG + 1];
vector<int> adj[MM];
vector<int> perm,leaf;
ll w[MM];
void pdfs(int u)
{
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        pdfs(v);
    }
}

int LCK(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v])
            u = up[u][i];
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

namespace subtask1
{
    void dfs(int u)
    {
        for(auto v:adj[u]) {
            if(up[u][0] == v) continue;
            w[v] = w[u] + color[v];
            dfs(v);
        }
    }

    void solve()
    {
        ll ans = 0;
        for(int i = 1;i <= n;i++) perm.push_back(i);
        for(int i = 1;i <= n;i++)
            color[i] = a[i];

        w[1] = color[1];
        dfs(1);
        ll res = 0;
        for(int i = 0;i < leaf.size();i++)
            for(int j = i + 1;j < leaf.size();j++) {
                int u = leaf[i], v = leaf[j];
                int lca = LCK(u,v);
                res += w[u] + w[v] - 2 * w[lca] + color[lca];
            }
        ans = max(ans,res);

        while(next_permutation(perm.begin(),perm.end())) {
            for(int i = 1;i <= n;i++) color[ perm[i - 1] ] = a[i];
            w[1] = color[1];
            dfs(1);
            ll res = 0;
            for(int i = 0;i < leaf.size();i++)
                for(int j = i + 1;j < leaf.size();j++) {
                    int u = leaf[i], v = leaf[j];
                    int lca = LCK(u,v);
                    res += w[u] + w[v] - 2 * w[lca] + color[lca];
                }
            ans = max(ans,res);
        }       
        cout << ans % MOD << '\n';
    }

    void build()
    {
        for(int i = 1;i <= n;i++) if(adj[i].size() == 1) leaf.push_back(i);
        pdfs(1);
        up[1][0] = 1;
        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i <= n;i++)
                up[i][j] = up[ up[i][j-1] ][j-1];
        solve();
        for(int i = 1;i <= n;i++) {
            adj[i].clear();
            h[i] = 0;
            w[i] = 0;
            color[i] = 0;
        }
        for(int i = 1;i <= n;i++)
            for(int j = 0;j <= LOG;j++)
                up[i][j] = 0;
        leaf.clear();
        perm.clear();
    }

}

namespace sol
{
    int isleaf[MM];
    ll c[MM],subleaf[MM],cntpath[MM],K = 0;
    void dfs(int u,int par)
    {
        subleaf[u] = isleaf[u];
        for(auto v:adj[u]) {
            if(v == par) continue;
            w[v] = w[u] + color[v];
            dfs(v,u);
            subleaf[u] += subleaf[v];
            cntpath[u] += subleaf[v] * subleaf[v];
        }
        if(!isleaf[u]) cntpath[u] += (K - subleaf[u]) * (K - subleaf[u]);
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) if(adj[i].size() == 1) {
            isleaf[i] = 1;
            leaf.push_back(i);
        }
        K = leaf.size();
        dfs(1,0);
        for(int i = 1;i <= n;i++) {
            ll total = (K * K - cntpath[i]) / 2;
            c[i] = total;
            if(isleaf[i]) c[i] = K - 1;
        }
        sort(c+1,c+n+1);
        sort(a+1,a+n+1);
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            res = (res + c[i] % MOD * a[i] % MOD) % MOD;
        }
        cout << res << '\n';

        for(int i = 1;i <= n;i++) {
            adj[i].clear();
            isleaf[i] = 0;
            cntpath[i] = subleaf[i] = 0;
        }
        leaf.clear();
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
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i < n;i++) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        sol::solve();
    }
    return 0;
}