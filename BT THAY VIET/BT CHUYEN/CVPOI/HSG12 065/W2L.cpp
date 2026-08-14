#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e7
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,num[MM],low[MM],timeDFS = 0,comp[MM],sz = 0,del[MM],scc[MM];
vector<int> adj[MM],g[MM],C[MM];
stack<int> st;
vector<pii> edges;

void tarjan(int u,int par)
{
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for(auto v:adj[u]) {
        if(del[v]) continue;
        if(!num[v]) {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }

    if(low[u] == num[u]) {
        int v, num = 0;
        sz++; 
        do
        {
            v = st.top(); st.pop();
            comp[v] = sz;
            del[v] = 1;
            num++;
            C[sz].push_back(v);
        } while(v != u);

        if(num != 1) scc[sz] = 1;
    }
}

int dp[MM],indeg[MM];
vector<int> topo;

void kahn()
{
    queue<int> q;
    for(int i = 1;i <= sz;i++) {
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
                topo.push_back(v);
                q.push(v);
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "W2L"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m; n++;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
        adj[u].push_back(v);
    }

    for(int i = 1;i <= n;i++) {
        if(!num[i])
            tarjan(i,0);
    }


    for(auto E:edges) {
        int u = E.fi, v = E.se;
        if(u == v) {
            scc[ comp[u] ] = 1;
        }

        if(comp[u] != comp[v]) {
            g[ comp[v] ].push_back( comp[u] );
            indeg[ comp[u] ]++;
        }
    }

    kahn();

    memset(dp,0,sizeof(dp));
    dp[ comp[n] ] = 1;

    vector<int> tower;
    for(auto u:topo) {
        if(dp[u] == 0) continue;
        if(scc[u]) dp[u] = oo;
        for(auto v:g[u]) {
            if(dp[u] == oo) dp[v] = oo;
            else dp[v] += dp[u];
            if(dp[v] > 36500) dp[v] = oo;
        }
    }

    int res = 0, res_sz = 0;

    for(int i = 1;i <= n-1;i++) {
        res = max(res,dp[comp[i]]);
    }

    for(int i = 1;i <= sz;i++) {
        if(dp[i] == res) {
            tower.push_back(i);
            res_sz += C[i].size();
        }
    }

    vector<int> vec;
    for(auto e:tower) {
        for(auto u:C[e])
            vec.push_back(u);
    }

    sort(vec.begin(),vec.end());
    cout << (res == oo ? -1 : res) << '\n';
    cout << res_sz << '\n';
    for(auto u:vec) cout << u << ' ';
    return 0;
}