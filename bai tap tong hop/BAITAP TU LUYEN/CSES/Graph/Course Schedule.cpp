#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,m,deg[MM];
vector<int> adj[MM],ans;


bool Kahn()
{
    queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(!deg[i]) {
            q.push(i);
            ans.push_back(i);
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for(auto v:adj[u]) {
            deg[v]--;
            if(deg[v] == 0) {
                q.push(v);
                ans.push_back(v);
            }
        }
    }
    return cnt == n;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    if(Kahn()) {
        for(auto i:ans) cout << i << ' ';
    }
    else cout << "IMPOSSIBLE";
    return 0;
}