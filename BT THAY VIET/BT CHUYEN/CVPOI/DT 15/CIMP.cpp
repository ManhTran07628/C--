#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MOD = 363636363;
const int MM = 500 + 7;
int n,m,d[MM][MM],cnt[MM][MM];
vector<pii> adj[MM];
struct Edge{int u,v,w;};
vector<Edge> edges;

struct Node{int u,dist_;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

void dijk(int st)
{
    for(int i = 1;i <= n;i++) d[st][i] = oo;
    d[st][st] = 0;
    cnt[st][st] = 1;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u;
        if(N.dist_ > d[st][u]) continue;
        for(auto U:adj[u]) {
            int v = U.fi, w = U.se;

            if(d[st][v] == d[st][u] + w) {
                cnt[st][v] += cnt[st][u];
                cnt[st][v] %= MOD;
            }

            if(d[st][v] > d[st][u] + w) {
                d[st][v] = d[st][u] + w;
                cnt[st][v] = cnt[st][u];
                q.push({v,d[st][v]});
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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1;i <= n;i++) dijk(i);

    set<int> res;
    for(int c = 1;c <= n;c++) {
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) {
                if(i == c || j == c) continue;
                if(d[i][c] + d[c][j] == d[i][j] && 
                cnt[i][c] * cnt[c][j] % MOD == cnt[i][j] % MOD) res.insert(c);
            }
        }
    }

    for(auto e:res) cout << e << ' ';
    if(res.size() == 0) cout << "No important cities.";
    return 0;
}
