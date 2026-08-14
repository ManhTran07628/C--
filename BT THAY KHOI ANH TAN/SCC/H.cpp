#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define oo 1e18
const int MM = 3e5 + 7;
int n,m;
int del[MM],num[MM],low[MM],comp[MM],timeDFS = 0,sz = 0;
vector<pii> adj[MM];
vector<int> Nadj[MM];
stack<int> st;
vector<pii> edges;

void tarjan(int u,int las)
{
    st.push(u);
    num[u] = low[u] = ++timeDFS;
    for(auto N:adj[u]) {
        int v = N.fi, id = N.se;
        if(id == las) continue;
        if(!num[v]) {
            tarjan(v,id);
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
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
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
            Nadj[scc_u].push_back(scc_v);
            Nadj[scc_v].push_back(scc_u);
        }
    }

    int cnt = 0;
    for(int i = 1;i <= sz;i++) {
        if(Nadj[i].size() == 1) cnt++;
    }
    cout << (cnt + 1) / 2;

    // for(int i = 1;i <= n;i++) cout << i << ' ' << num[i] << ' ' << low[i] << ' ' << comp[i] << '\n';

    return 0;
}