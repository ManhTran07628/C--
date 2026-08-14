#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,S,scc_Node[MM],scc = 0,num[MM],low[MM],timeDFS = 0;
ll vis[MM],scc_w[MM],indeg[MM];
ll dp[MM],ans = 0;
vector<pair<int,ll>> adj[MM],Nadj[MM];
struct edge{ll u,v,w;}; vector<edge> edges;



ll total_mushrooms(ll w)
{
    ll l = 0,r = 1e8,k = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(mid*(mid-1) <= w*2) {
            k = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    ll s = k*w - k*(k-1)*(k+1)/6;
    return s;
}

void loadgraph()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        edges.push_back({x,y,w});
    }
    cin >> S;
}

stack<int> st;
void tarjan(int u)
{   
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for(auto x:adj[u]) {
        int v = x.fi, w = x.se;
        if(scc_Node[v]) continue;
        if(!num[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }

    if(num[u] == low[u]) {
        int v;
        scc++;
        do
        {
            v = st.top(); st.pop();
            scc_Node[v] = scc;
        } while (v != u);
    }
}

void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= scc;i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto x:Nadj[u]) {
            ll v = x.fi, w = x.se;
            if(dp[u] != -oo) {
                dp[v] = max(dp[v],dp[u] + w + scc_w[v]);
                ans = max(ans,dp[v]);
            }
            indeg[v]--;
            if(!indeg[v]) q.push(v);
        }
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);

    for(auto E:edges) {
        ll u = E.u, v = E.v, w = E.w;
        if(scc_Node[u] == scc_Node[v]) {
            scc_w[scc_Node[u]] += total_mushrooms(w);
        }
        else {
            Nadj[scc_Node[u]].push_back({scc_Node[v],w});
            indeg[scc_Node[v]]++;
        }
    }
    fill(dp,dp+scc+2,-oo);
    dp[scc_Node[S]] = scc_w[scc_Node[S]];
    ans = scc_w[scc_Node[S]];

    memset(vis,0,sizeof(vis));
    Kahn();
    cout << ans;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadgraph();
    solve();
    return 0;
}