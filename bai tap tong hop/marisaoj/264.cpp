#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 5e4;
const int LOG = 16;
int n,q,a[MM + 1],lim;
vector<int> adj[MM + 1],Node[MM + 1];
struct dl{int u,x,id;} qr[MM + 1];
int up[MM + 1][LOG + 1],h[MM + 1],old[MM + 1],nval[MM + 1];
vector<int> v;
vector<int> dist[MM];

// bai nay cai LCK O(1) moi AC duoc nhe muon cai LCK O(LOG) thi phai dung black magic
void dfs(int u)
{
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int lca(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v])
            u = up[u][i];
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

void process()
{
    lim = (int) sqrt(n);
    dfs(1); up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];

    for(int i = 1;i <= q;i++) {
        cin >> qr[i].u >> qr[i].x; qr[i].id = i;
        if(Node[ qr[i].x ].size() >= lim) v.push_back(qr[i].x);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0;i < v.size();i++) {
        old[i] = v[i];
        nval[ old[i] ] = i;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        Node[ a[i] ].push_back(i);
    }
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    process();

    queue<int> Q;
    for(int t = 0;t < v.size();t++) {
        dist[t].push_back(0);
        for(int i = 1;i <= n;i++) dist[t].push_back(oo);

        for(auto v: Node[ old[t] ]) {
            Q.push(v);
            dist[t][v] = 0;
        }
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(auto v:adj[u]) {
                if(dist[t][v] > dist[t][u] + 1) {
                    dist[t][v] = dist[t][u] + 1;
                    Q.push(v);
                }
            }
        }   
    }

    for(int i = 1;i <= q;i++) {
        if(Node[ qr[i].x ].size() == 0) cout << -1 << '\n';
        else if(Node[ qr[i].x ].size() < lim) {
            int u = qr[i].u, res = oo;
            for(auto v: Node[ qr[i].x ]) {
                int dist = h[u] + h[v] - 2 * h[ lca(u,v) ];
                res = min(res,dist);
            }
            cout << res << '\n';
        }
        else {
            int res = dist[ nval[ qr[i].x ] ][ qr[i].u ];
            cout << res << '\n'; 
        }
    }


    
    return 0;   
}