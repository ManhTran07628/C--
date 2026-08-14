#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n,m,q,mark[MM];
ll w[MM],ans[MM];
vector<int> adj[MM];
vector<pair<int,int>> edges;
stack<ll> Val[MM];
struct Qr{char type; int i,k;} qr[MM];

multiset<ll> maxval;

void init()
{
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        cin >> w[i];
        Val[i].push( w[i] );
    }
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    for(int i = 1;i <= q;i++) {
        qr[i].k = 0;
        cin >> qr[i].type >> qr[i].i;
        if(qr[i].type == 'C') {
            cin >> qr[i].k;
            Val[ qr[i].i ].push( qr[i].k );
        }
        else mark[ qr[i].i ] = 1;
    }
}

struct DSU
{
    vector<int> par,sz;
    vector<ll> comp_val;

    DSU(int n) : par(n+7),sz(n+7),comp_val(n+7)
    {
        for(int i = 1;i <= n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        par[b] = a;
        maxval.erase( maxval.find( comp_val[a] ) );
        maxval.erase( maxval.find( comp_val[b] ) );
        comp_val[a] += comp_val[b];
        maxval.insert( comp_val[a] );
    }
};



void solve()
{
    DSU g(n);

    
    
    for(int i = 1;i <= n;i++) {
        g.comp_val[i] = Val[i].top();
        maxval.insert( g.comp_val[i] );
        w[i] = Val[i].top();
        Val[i].pop();
    }

    for(int i = 1;i <= m;i++) {
        if(!mark[i]) {
            adj[ edges[i-1].fi ].push_back( edges[i-1].se );
            adj[ edges[i-1].se ].push_back( edges[i-1].fi );
            g.Unite(edges[i-1].fi,edges[i-1].se );
        }
    }
    
    // cout << *maxval.rbegin();

    for(int i = q;i >= 1;i--) {
        ans[i] = *maxval.rbegin();
        if(qr[i].type == 'D') g.Unite(edges[ qr[i].i-1 ].fi,edges[ qr[i].i-1 ].se);
        else {
            int root = g.find_sets( qr[i].i );
            maxval.erase( maxval.find( g.comp_val[ root ] ) );
            g.comp_val[ root ] = g.comp_val[ root ] + Val[ qr[i].i ].top() - w[ qr[i].i ];
            w[ qr[i].i ] = Val[ qr[i].i ].top();
            maxval.insert( g.comp_val[ root ] );

            Val[ qr[i].i ].pop();


        }
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}