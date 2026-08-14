#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,k;
vector<pii> adj[MM];

priority_queue<ll> d[MM];

struct Node{ll u,dist_;}; 
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

void dijk()
{
    d[1].push(0);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u;
        if(N.dist_ > d[u].top()) continue;
        for(auto U:adj[u]) {
            ll v = U.fi, w = U.se;
            if(d[v].size() < k) {
                d[v].push(N.dist_ + w);
                q.push({v,N.dist_ + w});
            }
            else if(d[v].top() > N.dist_ + w) {
                d[v].pop();
                d[v].push(N.dist_ + w);
                q.push({v,N.dist_ + w});
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
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijk();
    vector<ll> ans;
    while(!d[n].empty()) {
        ans.push_back(d[n].top());
        d[n].pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto e:ans) cout << e << ' ';
    return 0;
}