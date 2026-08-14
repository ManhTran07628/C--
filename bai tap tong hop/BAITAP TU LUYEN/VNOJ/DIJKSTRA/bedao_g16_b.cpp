#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,ll>
const int MM = 2e5+7;
int n,m,comps[MM],comps_sz = 0,num[MM],low[MM],timeDFS = 0,del[MM];
int vis[MM],stt,indeg[MM];
ll comps_val[MM],dist[MM];
vector<pii> adj[MM],Nadj[MM],rev[MM];
struct Edge{int u,v,w;};
vector<Edge> edges;

int inStack[MM];
stack<int> st;
void tarjan(int u)
{
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    inStack[u] = 1;

    for(auto X: adj[u]) {
        int v = X.fi;
        if(!num[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if(num[u] == low[u]) {
        comps_sz++;
        int v;
        do {
            v = st.top(); st.pop();
            inStack[v] = 0;
            comps[v] = comps_sz;
            if(v == 1) stt = comps_sz;
        } while(v != u);
    }
}


vector<int> topo;
void kahn()
{
    queue<int> q;
    for(int i = 1;i <= comps_sz;i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(auto X: Nadj[u]) {
            int v = X.fi, w = X.se;
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto X:Nadj[u]) {
        int v = X.fi;
        if(!vis[v]) dfs(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        edges.push_back({u,v,w});
    }
    for(int i = 1;i <= n;i++)
        if(!num[i]) tarjan(i);

    for(int i = 0;i < m;i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if(comps[u] == comps[v]) {
            ll vals = 0;
            while(w > 0) {
                vals += w;
                w /= 2;
            }
            comps_val[ comps[u] ] += vals;
        }
        else {
            indeg[ comps[v] ]++;
            Nadj[ comps[u] ].push_back({ comps[v],w });
        }
    }
    kahn();

    for(int i = 1; i <= comps_sz; i++) dist[i] = -oo;
    dist[comps[1]] = 0;


    ll res = 0;
    for(auto u:topo) {
        // cout << u << ' ';
        if(dist[u] < 0) continue;
        dist[u] += comps_val[u];
        for(auto X: Nadj[ u ]) {
            ll v = X.fi, w = X.se;
            dist[v] = max(dist[v], dist[u] + w);
        }
    }

    for(int i = 1;i <= comps_sz;i++) {
        res = max(res,dist[i]);
    }
    cout << res;
    return 0;
}
