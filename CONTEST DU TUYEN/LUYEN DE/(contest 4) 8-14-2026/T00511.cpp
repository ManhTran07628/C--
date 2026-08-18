#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
int n,m,in[MM],out[MM],timeDFS = 0;
ll c[MM],L[MM],R[MM],ans[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    in[u] = ++timeDFS;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    out[u] = timeDFS;
}

pii watered[MM];

vector<int> queries[MM];

ll bit[MM];

void update(int x,ll val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

ll get(int x)
{
    ll res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void update_range(int l,int r,ll val)
{
    update(l,val);
    update(r + 1,-val);
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
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= m;i++) {
        cin >> watered[i].fi >> watered[i].se;
    }

    for(int i = 1;i <= n;i++) {
        L[i] = 1, R[i] = m, ans[i] = -1;
    }

    while(1) {
        bool ok = 1;
        for(int i = 1;i <= n;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            queries[ (L[i] + R[i]) / 2 ].push_back(i);
        }

        if(ok) break;

        for(int mid = 1;mid <= m;mid++) {
            int v = watered[mid].fi;
            ll w = watered[mid].se;
            update_range(in[v],out[v],w);

            for(auto id:queries[mid]) {
                ll val = get(in[id]);
                if(c[id] <= val) {
                    ans[id] = mid;
                    R[id] = mid - 1;
                }
                else L[id] = mid + 1;
            }

            queries[mid].clear();
        }

        fill(bit+1,bit+n+1,0);
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';

    return 0;
}