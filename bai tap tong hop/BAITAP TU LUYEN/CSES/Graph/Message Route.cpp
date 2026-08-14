#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<vector<int>> adj(MAXN);
int parent[MAXN],visited[MAXN];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u:adj[v]) {
            if(!visited[u]) {
                parent[u] = v;
                visited[u] = 1;
                q.push(u);
            }
        }
    }
}

void Path(int s,int t)
{
    bfs(s);
    if(!visited[t]) {
        cout << "IMPOSSIBLE";
        return;
    }
    else {
        vector<int> path;
        while(s != t) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        cout << path.size() << '\n';
        for(auto x:path) cout << x << ' ';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Path(1,n);
    return 0;
}