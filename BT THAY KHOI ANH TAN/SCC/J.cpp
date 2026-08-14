#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define oo 1e18
const int MM = 3e5 + 7;
int n,m;
int del[MM],num[MM],low[MM],comp[MM],timeDFS = 0,sz = 0,in[MM],out[MM];
vector<int> adj[MM];
vector<int> Nadj[MM];
stack<int> st;
vector<pii> edges;


void tarjan(int u,int par)
{
    st.push(u);
    num[u] = low[u] = ++timeDFS;
    for(auto v:adj[u]) {
        if(del[v]) continue;
        if(!num[v]) {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }

    if(num[u] == low[u]) {
        int v;
        sz++;
        do
        {
            v = st.top(); st.pop();
            comp[v] = sz;
            del[v] = 1;

        } while(v != u);
        
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "DOANDUONGPHU"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }
    for(int i = 1;i <= n;i++) {
        if(!num[i]) {
            tarjan(i,0);
        }
    }

    for(auto E:edges) {
        int u = E.fi, v = E.se;
        int scc_u = comp[u], scc_v = comp[v];
        if(scc_u != scc_v) {
            in[scc_v]++;
            out[scc_u]++;
        }
    }

    int x = 0,y = 0;
    for(int i = 1;i <= sz;i++) {
        if(!in[i]) x++;
        if(!out[i]) y++;
    }

    cout << max(x,y);
    return 0;
}