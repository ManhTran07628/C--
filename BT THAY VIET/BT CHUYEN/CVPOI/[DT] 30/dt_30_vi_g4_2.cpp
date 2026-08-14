#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,c[MM],sz = 0,indeg[MM],vis[MM];
vector<int> g[MM],topo;
vector<pii> adj[MM],radj[MM];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:g[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

void kahn()
{
    queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(indeg[i] == 0) {
            q.push(i);
            topo.push_back(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                q.push(v);
                topo.push_back(v);
            }
        }
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
    cin >> n; // a[i] -> i
    for(int i = 1;i <= n;i++) {
        int a; cin >> a >> c[i];
        radj[i].push_back({a,c[i]});

        g[a].push_back(i);
        g[i].push_back(a);

        indeg[i]++;
    }
    int cc = 0;
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            dfs(i);
            cc++;
        }
    }
    kahn();
    memset(vis,0,sizeof(vis));
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        ll sum = 0, max_val = -1, node;
        cout << i << ": ";
        for(auto j:radj[i]) {
            cout << j.fi << ' ';
            if(max_val < j.se) {
                max_val = j.se;
                node = j.fi;
            }
            sum += j.se;
        } cout << '\n';
        if(max_val != -1) {
            adj[i].push_back({node,max_val});
            adj[node].push_back({i,max_val});
            res += sum - max_val;
        }
    }
    cout << res;
    return 0;
}