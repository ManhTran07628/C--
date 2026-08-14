#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<ll,ll> 
const int MM = 3e5+7;
const int LOG = 18;
int n,q,par[MM],up[MM][LOG+1],h[MM],m = 0;
ll Min[MM][LOG+1];
int num[MM],en[MM],tour[MM];
struct Node{ll u,w,c,s;} path[MM];

struct Edge{int x,y;ll v,c,s;};
vector<Edge> edges;

struct QR{ll a,b,m,lca;} qr[MM];

vector<vector<Node>> adj; 

struct query{
    ll w,id;
};

struct cmp{
    bool operator() (query a,query b) {
        return a.w > b.w;
    }
};

void dfs(int u)
{
    tour[++m] = u;
    num[u] = m;
    for(auto x:adj[u]) {
        int v = x.u,w = x.w,c = x.c,s = x.s;
        if(v != up[u][0]) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            path[v].u = v; path[v].w = w; path[v].c = c; path[v].s = s;
            par[v] = u;
            Min[v][0] = s;
            dfs(v);
        }
    }
    en[u] = m;
}

void buildlca()
{
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            Min[i][j] = min(Min[i][j-1],Min[up[i][j-1]][j-1]);
        }
    }
}

int lca(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) 
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

ll valss(ll u,ll v)
{
    ll Lca = lca(u,v);
    ll dis1 = h[u] - h[Lca], dis2 = h[v] - h[Lca];
    ll minlen = oo;
    for(int i = LOG;i >= 0;i--) {
        if(dis1 >> i & 1) {
            minlen = min(minlen,Min[u][i]);
            u = up[u][i];
        }
    }

    for(int i = LOG;i >= 0;i--) {
        if(dis2 >> i & 1) {
            minlen = min(minlen,Min[v][i]);
            v = up[v][i];
        }
    }
    return minlen;
}

namespace subtask1
{
    // u,w,c,s;
    // dinh u , trong so ban dau w , chi phi upgrade c , s trong so sau upgrade
    // id w 
    void solve()
    {
        while(q--) {
            ll a,b,m;
            priority_queue<query,vector<query>,cmp> q;
            cin >> a >> b >> m;
            int Lca = lca(a,b);
            while(a != Lca) {
                q.push({path[a].w,a});
                a = par[a];
            }
            while(b != Lca) {
                q.push({path[b].w,b});
                b = par[b];
            }
            ll ans = oo;
            while(!q.empty()) {
                ll min_val = q.top().w,id = q.top().id;
                if(m >= path[id].c) {
                    min_val = path[id].s;
                    m -= path[id].c;
                }
                ans = min(ans,min_val);
                q.pop();
            }
            cout << ans << '\n';
        }
    }
}

namespace subtask3
{
    ll L[MM],R[MM],ans[MM];

    struct BIT
    {
        vector<ll> bit;
        BIT(int n) : bit(n + 7) {};

        void resetbit()
        {
            fill(bit.begin(),bit.end(),0);
        }

        void update(int x,ll val)
        {
            for(;x <= n;x += (x & -x))
                bit[x] += val;
        }

        ll get(int x)
        {
            ll res = 0;
            for(;x > 0;x -= (x & -x))
                res += bit[x];
            return res;
        }
    } fen(MM);

    void solve()
    {   
        // buildlca();
        for(int i = 1;i <= q;i++) {
            cin >> qr[i].a >> qr[i].b >> qr[i].m;
            L[i] = 0, R[i] = valss(qr[i].a,qr[i].b); 
            qr[i].lca = lca(qr[i].a, qr[i].b);
        }
        sort(edges.begin(),edges.end(), [] (Edge a,Edge b){
            return a.v < b.v;
        });

        while(1) {
            vector<pii> queries;
            bool ok = 1;
            for(int i = 1;i <= q;i++) {
                if(L[i] > R[i]) continue;
                ok = 0;
                queries.push_back({ (L[i] + R[i]) / 2, i});
            }
            if(ok) break;
            fen.resetbit();

            sort(queries.begin(),queries.end(),[] (pii a,pii b){
                return a.fi < b.fi;
            });

            int i = 0;
            for(auto M:queries) {
                ll mid = M.fi, id = M.se;
                while(i < edges.size() && edges[i].v < mid) {
                    int u = edges[i].x, v = edges[i].y;
                    int child = (par[u] == v ? u : v);
                    fen.update(num[ child ], edges[i].c);
                    fen.update(en[ child ] + 1, -edges[i].c);
                    i++;
                }
                ll budget = fen.get(  num[ qr[id].a ] ) + fen.get( num[ qr[id].b ] )
                    - 2 * fen.get( num[ qr[id].lca ] );
                if(budget <= qr[id].m) {
                    ans[id] = mid;
                    L[id] = mid + 1;
                }
                else R[id] = mid - 1;
            }
        }

        for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n+1);
    for(int i = 1;i < n;i++) {
        int x,y,v,c,s;
        cin >> x >> y >> v >> c >> s;
        edges.push_back({x,y,v,c,s});
        adj[x].push_back({y,v,c,s});
        adj[y].push_back({x,v,c,s});
    }
    up[1][0] = 1;
    buildlca();
    cin >> q;
    // if(n <= 1000 && q <= 1000) subtask1::solve();
    subtask3::solve();
    // cout << valss(2,4);
    return 0;
}