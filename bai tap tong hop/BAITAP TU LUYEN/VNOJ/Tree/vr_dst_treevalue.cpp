#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,a[MM],ans[MM],h[MM];
vector<int> adj[MM];
int bit[MM];

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) 
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
}

void update(int x,int val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

int get(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void dfs(int u,int par)
{
    ans[u] = h[u] - get(a[u]);
    update(a[u],1);
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
    update(a[u],-1);

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    coordcompress();
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';

    return 0;
}