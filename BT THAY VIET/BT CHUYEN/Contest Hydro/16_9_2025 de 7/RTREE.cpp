#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e5+7;
const int LOG = 20;
ll n,q,Val[MM],sumNode[MM],up[MM][LOG+1],f[MM],h[MM];
vector<int> adj[MM];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> Val[i];
    for(int u = 2;u <= n;u++) {
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u)
{
    sumNode[u] += Val[u];
    for(auto v:adj[u]) {
        if(up[u][0] != v) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
            sumNode[u] += sumNode[v];
            f[u] += f[v] + sumNode[v];
        }
    }
}

int binlift(int u,int k)
{
    for(int i = LOG;i >= 0;i--) {
        if(k >> i & 1) {
            u = up[u][i];
        }
    }
    return u;
}

void solve()
{
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    while(q--) {
        int u,v;
        cin >> u >> v;
        if(up[u][0] == v) {
            cout << f[v] << '\n';
        }
        else {
            int len = h[u] - h[v] - 1;
            int child_v = binlift(u,len);
            cout << f[v] + sumNode[child_v] - sumNode[u] - len*Val[u] << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}