#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m,h[MM],indeg[MM],vis[MM];
vector<int> adj[MM],g[MM];

void dfs(int u)
{
    for(auto v:g[u]) {
        h[v] = h[u] + 1;
        dfs(v);
    }
}

struct Node{int u,d;};

struct cmp{bool operator() (Node a,Node b){return a.d < b.d;}};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        g[v].push_back(u);
        indeg[v]++;
    }
    for(int i = 1;i <= n;i++) {
        if(adj[i].size() == 0) {
            dfs(i);
            break;
        }
    }
    priority_queue<Node,vector<Node>,cmp> q;
    for(int i = 1;i <= n;i++) {
        if(indeg[i] == 0) {
            q.push({i,h[i]});
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        int cur = m;
        vector<int> temp;
        while(cur > 0 && !q.empty()) {
            Node N = q.top(); q.pop();
            int u = N.u, d = N.d;
            for(auto v:adj[u]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    temp.push_back(v);
                }
            }
            cur--;
        }
        for(auto e:temp) q.push({e,h[e]});
        cnt++;
    }
    cout << cnt;

    return 0;
}
