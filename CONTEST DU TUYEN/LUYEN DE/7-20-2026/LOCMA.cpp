#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e3 + 7;
const int lim = 9;
int n,m,s,t,X;
int a[MM],c[MM];
vector<pii> adj[MM];

ll d[MM][1 << lim];
struct Node{ll u,dist_,mask;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

const int MS = 5e4;
int prime[MS];
vector<int> primes,tsnt;
void sieve()
{
    for(int i = 2;i < MS;i++)
        prime[i] = 1;

    for(int i = 2;i * i < MS;i++)
        if(prime[i])
            for(int j = i * i;j < MS;j += i)
                prime[j] = 0;
                
    for(int i = 2;i < MS;i++)
        if(prime[i])
            primes.push_back(i);

    ll x = X;
    for(auto p:primes) {
        if(p > x) break;
        if(x % p == 0) {
            tsnt.push_back(p);
            while(x % p == 0) x /= p;
        }
    }
    if(x > 1) tsnt.push_back(x);
}

unordered_map<int,int> mp;

void dijk(int s)
{
    for(int i = 1;i <= n;i++)
        for(int mask = 0;mask < (1 << lim);mask++)
            d[i][mask] = oo;

    d[s][(1 << lim) - 1] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({s,0,(1 << lim) - 1});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u, cur_mask = N.mask;
        if(d[u][cur_mask] < N.dist_) continue;
        
        int new_state = a[u] & cur_mask;
        if(d[u][new_state] > d[u][cur_mask] + c[u]) {
            d[u][new_state] = d[u][cur_mask] + c[u];
            q.push({u,d[u][new_state],new_state});
        }

        for(auto U:adj[u]) {
            int v = U.fi, w = U.se;
            if(d[v][cur_mask] > d[u][cur_mask] + w) {
                d[v][cur_mask] = d[u][cur_mask] + w;
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
    cin >> n >> m >> s >> t >> X;
    tsnt.push_back(1);
    sieve();
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> c[i];

    for(int i = 0;i < tsnt.size();i++) mp[ tsnt[i] ] = i;

    for(int i = 1;i <= n;i++) {
        int mask = 0;
        for(int j = 0;j < tsnt.size();j++) 
            if(a[i] % tsnt[j] == 0) 
                mask |= (1 << j);
        a[i] = mask;
    }
    
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijk(s);
    if(d[t][1] == oo) cout << -1;
    else cout << d[t][1];
    // cout << d[t][1];
    return 0;
}