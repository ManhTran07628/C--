#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e3 + 7;
const int sz = 10;
int n,m,h,k,s,t;
struct serv{int v,color,cost_b;} service[20000];
vector<int> serv_list[MM];

struct Edge{int v,weight,color;};
vector<Edge> adj[MM];

struct Node{ll u,dist_,cur_mask;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

ll d[MM][1 << sz];

void dijk()
{
    for(int i = 1;i <= n;i++) {
        for(int mask = 0;mask < (1 << sz);mask++)
            d[i][mask] = oo;
    }
    priority_queue<Node,vector<Node>,cmp> q;
    d[s][0] = 0;
    q.push({s,0,0});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u, cur_mask = N.cur_mask;
        if(N.dist_ > d[u][cur_mask]) continue;

        for(auto id:serv_list[u]) {
            int nxt_color = service[id].color, cost_b = service[id].cost_b;
            if(cur_mask >> nxt_color & 1) continue;

            int new_mask = cur_mask | (1 << nxt_color);
            if(d[u][new_mask] > d[u][cur_mask] + cost_b) {
                d[u][new_mask] = d[u][cur_mask] + cost_b;
                q.push({u,d[u][new_mask],new_mask});
            } 
        }
        
        for(auto U:adj[u]) {
            int v = U.v, color = U.color, weight = U.weight;
            if((cur_mask >> color & 1) && d[v][cur_mask] > d[u][cur_mask]) {
                d[v][cur_mask] = d[u][cur_mask];
                q.push({v,d[v][cur_mask],cur_mask});
            }

            if(d[v][cur_mask] > d[u][cur_mask] + weight) {
                d[v][cur_mask] = d[u][cur_mask] + weight;
                q.push({v,d[v][cur_mask],cur_mask});
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
    cin >> n >> m >> h >> k >> s >> t;
    for(int i = 1;i <= h;i++) {
        cin >> service[i].v >> service[i].color >> service[i].cost_b;
        serv_list[ service[i].v ].push_back(i);
    }

    for(int i = 1;i <= m;i++) {
        int u,v,w,c; cin >> u >> v >> w >> c;
        adj[u].push_back({v,w,c});
    }
    
    dijk();
    ll res = oo;
    for(int mask = 0;mask < (1 << sz);mask++) res = min(res,d[t][mask]);
    cout << (res == oo ? -1 : res);
    return 0; 
}