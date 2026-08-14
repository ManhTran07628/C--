#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,in_deg[MM],ok = 1,ds[MM];
vector<int> adj[MM];

void bfs()
{
    queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(in_deg[i] == 0) {
            q.push(i);
            ds[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            in_deg[v]--;
            if(in_deg[v] == 0) {
                q.push(v);
                ds[v] = 1;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!ds[i]) ok = 0;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_deg[v]++;
    }
    bfs();
    cout << (ok == 1 ? "Y":"N");
    return 0;
}