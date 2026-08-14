#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,m,q;
vector<int> adj[MM];
vector<pair<int,int>> edges;
struct dl
{
    int u,v,id;
};
dl qr[MM];
void readinput()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u,v});
    }
    cin >> q;
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].u >> qr[i].v;
        qr[i].id = i;
    }
}

namespace subtask1
{
    const int MS = 107;
    vector<int> adj[MS];
    int cnt = 0;
    bool vis[MS];
    void process(int l,int r)
    {
        memset(vis,0,sizeof(vis));
        cnt = 0;
        for(int i = 1;i <= n;i++) adj[i].clear();

        for(int i = l;i <= r;i++) {
            adj[edges[i-1].fi].push_back(edges[i-1].se);
            adj[edges[i-1].se].push_back(edges[i-1].fi);
        }
    }

    void dfs(int u)
    {
        cnt++;
        vis[u] = 1;
        for(auto v:adj[u]) {
            if(!vis[v]) {
                dfs(v);
            }
        }
    }

    void solve()
    {
        for(int i = 1;i <= q;i++) {
            process(qr[i].u,qr[i].v);
            dfs(1);
            cout << (cnt == n ? "Yes" : "No") << '\n';

        }
    }
}

namespace subtask2
{
    int cur_id = 1,cnt = 0,ans[MM],ok = 0;
    bool vis[MM];
    vector<int> adj[MM];
    bool checksub2()
    {
        for(int i = 1;i <= n;i++) {
            if(qr[i].u != 1) return 0;
        }
        return 1;
    }

    void process(int l,int r)
    {
        cnt = 0;
        memset(vis,0,sizeof(vis));
        for(int i = l;i <= r;i++) {
            adj[edges[i-1].fi].push_back(edges[i-1].se);
            adj[edges[i-1].se].push_back(edges[i-1].fi);
        }
    }

    void dfs(int u)
    {
        cnt++;
        vis[u] = 1;
        for(auto v:adj[u]) {
            if(!vis[v]) {
                dfs(v);
            }
        }
    }

    void solve()
    {
        sort(qr+1,qr+q+1, [] (dl &a, dl &b){
            return a.v < b.v;
        });

        for(int i = 1;i <= q;i++) {
            if(qr[i].v == qr[i-1].v) continue;

            if(ok) {
                ans[qr[i].id] = 1;
                continue;
            }

            process(cur_id,qr[i].v);
            dfs(1);
            ans[qr[i].id] = (cnt == n);
            if(ans[qr[i].id]) {
                ok = 1;
            }
            cur_id = qr[i].v + 1;
        }

        for(int i = 1;i <= q;i++) {
            cout << (ans[i] == 1 ? "Yes" : "No") << '\n';
        }
    }
}

namespace subtask3
{
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "GRAPH"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    readinput();
    if(m <= 100 && q <= 100) subtask1::solve();
    else if(subtask2::checksub2()) subtask2::solve();
    else subtask1::solve();
    return 0;
}