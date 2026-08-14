#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int> 
const int MM = 1e5 + 7;
int n,m,k,c[MM],indeg[MM];
struct Node{int u;ll w;};
vector<int> adj[MM],radj[MM],Nadj[MM];
ll dist[MM][31];
struct SCC
{
    stack<int> st;
    int vis[MM] = {},comps[MM] = {};
    int comps_sz = 0;


    void dfs1(int u)
    {
        vis[u] = 1;
        for(auto v:adj[u]) {
            if(vis[v]) continue;
            dfs1(v);
        }
        st.push(u);
    }

    void dfs2(int u)
    {
        vis[u] = 1;
        comps[u] = comps_sz;
        for(auto v:radj[u]) {
            if(vis[v]) continue;
            dfs2(v);
        }
    }

    void process()
    {
        for(int i = 1;i <= n;i++) {
            if(!vis[i]) 
                dfs1(i);
        }

        memset(vis,0,sizeof(vis));
        while(!st.empty()) {
            int u = st.top(); st.pop();
            if(!vis[u]) {
                comps_sz++;
                dfs2(u);
            }
        } 
    }

    void dfs(int u)
    {   
        vis[u] = 1;
        for(auto v:adj[u]) {
            
            if(comps[u] != comps[v]) {
                int nxt_u = comps[u];
                int nxt_v = comps[v];
                Nadj[nxt_u].push_back(nxt_v);
                indeg[nxt_v]++;
            }
            
            if(vis[v]) continue;
            dfs(v);
        }
    }

    void make_adj()
    {
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++) {
            if(!vis[i]) dfs(i);
        }
    }

} scc;

multiset<int> ms[MM];


vector<int> topo;
void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= scc.comps_sz;i++) {
        if(indeg[i] == 0) {
            q.push(i);
            topo.push_back(i);
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto v:Nadj[u]) {
            indeg[v]--;
            if(!indeg[v]) {
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
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    scc.process();
    scc.make_adj();
    for(int i = 1;i <= n;i++) {
        int u = scc.comps[i];
        ms[u].insert(c[i]);
        while(ms[u].size() > k) {
            auto it = ms[u].begin();
            ms[u].erase(it);
        }
    }

    Kahn();
    ll res = 0;
    for(auto u:topo) {

        for(int i = k - 1;i >= 0;i--) {
            int cnt = 0;
            ll cur_cost = 0;
            for(auto it = ms[u].rbegin();it != ms[u].rend();it++) {
                cnt++;
                cur_cost += *it;
                if(cnt + i <= k)
                    dist[u][cnt + i] = max(dist[u][cnt + i],dist[u][i] + cur_cost);
            }
        }

        for(auto v:Nadj[u]) {
            for(int i = 1;i <= k;i++)
                dist[v][i] = max(dist[v][i],dist[u][i]);
        }
    }
    for(int i = 1;i <= scc.comps_sz;i++)
        for(int j = 1;j <= k;j++)
            res = max(res,dist[i][j]);
    cout << res;
    return 0;
}