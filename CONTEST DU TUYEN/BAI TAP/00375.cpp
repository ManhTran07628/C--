#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,m,q,L[MM],R[MM],ans[MM],good[MM];
vector<pii> edges,Q,safe;
map<pii,int> mp;

struct DSU
{
    int par[MM] = {}, sz[MM] = {};
    DSU() {
        for(int i = 1;i < MM;i++) {
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
        par[b] = a;
        sz[a] += sz[b];
    }
} g;

vector<int> queries[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        edges.push_back({u,v});

    }
    Q.push_back({0,0});
    for(int i = 1;i <= q;i++) {
        int u,v; cin >> u >> v;
        Q.push_back({u,v});    
        mp[{u,v}] = 1;
    }

    for(auto E:edges) {
        int u = E.fi, v = E.se;
        if(mp.find({u,v}) == mp.end()) {
            safe.push_back({u,v});
            g.Unite(u,v);
        }
    }

    for(int i = 2;i <= n;i++) {
        L[i] = 1, R[i] = q, ans[i] = 0;
        if(g.find_sets(1) == g.find_sets(i)) {
            ans[i] = -1;
            good[i] = 1;
        }
    }

    while(1) {
        bool ok = 1;
        for(int i = 2;i <= n;i++) {
            if(good[i]) continue;
            if(L[i] > R[i]) continue;
            ok = 0;
            queries[(L[i] + R[i]) / 2].push_back(i);
        }

        if(ok) break;

        for(int i = 1;i <= n;i++) {
            g.par[i] = i;
            g.sz[i] = 1;
        }

        for(auto E:safe) {
            int u = E.fi, v = E.se;
            g.Unite(u,v);
        }

        for(int mid = q;mid >= 1;mid--) {
            int u = Q[mid].fi, v = Q[mid].se;
            g.Unite(u,v);

            for(auto qr: queries[mid]) {
                if(g.find_sets(1) == g.find_sets(qr)) {
                    ans[qr] = mid;
                    L[qr] = mid + 1;
                }
                else R[qr] = mid - 1;
            }

            queries[mid].clear();
        }
    }

    for(int i = 2;i <= n;i++) {
        cout << ans[i] << '\n';
    }
        

    return 0;
}