#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e3+7;
vector<vector<int>> adj(MAXN),component(MAXN);
vector<int> compmark;
int mark[1001],visited[1001];

void dfs(int v,int anc)
{
    component[anc].push_back(v);
    visited[v] = 1;
    for(auto u:adj[v]) {
        if(!visited[u])
            dfs(u,anc);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,cnt = 0;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mark[u] = mark[v] = 1;
    }
    for(int i = 1;i <= n;i++) {
        if(!mark[i])
            adj[i].push_back(i);
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            cnt++;
            dfs(i,i);
            compmark.push_back(i);
            sort(component[i].begin(),component[i].end());
        }
    }
    cout << cnt << '\n';
    for(auto i:compmark) {
    cout << component[i].size() << ' ';
        for(auto u:component[i])
            cout << u << ' ';
        cout << '\n';
    }
    return 0;
}