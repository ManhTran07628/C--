#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int n,m;
vector<vector<int>> adj(MAXN);
vector<int> roads;
int visited[MAXN];
void dfs(int u)
{
    visited[u] = 1;
    for(auto v:adj[u]) {
        if(!visited[v])
            dfs(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            roads.push_back(i);
            dfs(i);
        }
    }
    cout << roads.size()-1 << '\n';
    for(int i = 0;i < roads.size()-1;i++) {
        cout << roads[i] << ' ' << roads[i+1] << '\n';
    }
    return 0;
}