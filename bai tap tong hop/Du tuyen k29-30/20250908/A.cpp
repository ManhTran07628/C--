#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,c[MM],ans[MM];
vector<int> adj[MM];

void ReadInput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

map<int,int> mp[MM];

void dfs(int u,int par)
{
    mp[u][c[u]]++;
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
            if(mp[u].size() < mp[v].size()) swap(mp[u],mp[v]);
            for(auto x:mp[v]) mp[u][x.fi]++;
        }
    }
    ans[u] = mp[u].size();
}

void solve()
{
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ReadInput();
    solve();
    return 0;
}