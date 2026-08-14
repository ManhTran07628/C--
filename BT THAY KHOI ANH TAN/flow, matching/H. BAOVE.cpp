#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 5e3 + 7;
int n,s,t;
ll max_flow = 0;
int c[MM][MM],r[MM][MM],trace[MM];
vector<int> adj[MM];

void bfs()
{
    fill(trace+1,trace+n+1,0);
    trace[s] = -1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(r[u][v] == 0 || trace[v]) continue;
            trace[v] = u;
            q.push(v);
        }
    }
}


void incFlow()
{
    int beta = oo;
    int cur = t;
    while(cur != s) {
        int v = trace[cur];
        beta = min(beta,r[v][cur]);
        cur = v;
    }

    cur = t;
    while(cur != s) {
        int v = trace[cur];
        r[v][cur] -= beta;
        r[cur][v] += beta;
        cur = v;
    }
    max_flow += beta;
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
    cin >> n;
    int u,v; 
    while(cin >> u) {
        cin >> v;
        cin >> c[u][v];
        r[u][v] = c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cout << u << ' ' << v << ' ' << c[u][v] << '\n';
    }
    s = n;
    t = 1;

    do  
    {
        bfs();
        if(trace[t]) incFlow();
    } while(trace[t]);

    cout << max_flow;
    return 0;
}
