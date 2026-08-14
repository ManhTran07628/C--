#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m,q,oldval[MM],sz = 0;
struct Edge{int u,v,w,k,id;};
vector<Edge> edges;
Edge qr[MM];
vector<int> queries[MM];

void coordcompress()
{
    vector<int> vec;
    for(int i = 0;i < m;i++) {
        vec.push_back(edges[i].w);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 0;i < m;i++) {
        int pos = lower_bound(vec.begin(),vec.end(),edges[i].w) - vec.begin() + 1;
        oldval[pos] = edges[i].w;
        edges[i].w = pos;
        // cout << i + 1 << ' ' << oldval[pos] << ' ' << pos << '\n';
    }
    sz = vec.size();
}

int L[MM],R[MM],ans[MM];

struct DSU
{
    int par[MM] = {}, sz[MM] = {};
    void build(int n)
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
        par[b] = a;
        sz[a] += sz[b];
    }
} g;

namespace sol
{
    void solve()
    {
        coordcompress();
        sort(edges.begin(),edges.end(),[] (Edge a,Edge b){return a.w < b.w;});
        for(int i = 1;i <= q;i++) {
            int u,v,k; cin >> u >> v >> k;
            qr[i].u = u; qr[i].v = v; qr[i].k = k;
            L[i] = 1, R[i] = sz, ans[i] = -1;
            if(u == v && k == 1) {
                ans[i] = 0;
                L[i] = 1; R[i] = 0;
            }
            // cout << L[i] << ' ' << R[i] << '\n';
        }
        // return;

        // for(auto E:edges) cout << E.u << ' ' << E.v << ' ' << E.w << '\n'; cout << sz;
        // return;
        while(1) {
            bool ok = 1;
            for(int i = 1;i <= q;i++) {
                if(L[i] > R[i]) continue;
                ok = 0;
                queries[ (L[i] + R[i]) / 2 ].push_back(i);
            }
            if(ok) break;

            g.build(n);
            int j = 0;
            for(int mid = 1; mid <= sz; mid++) {
                
                while(j < m && edges[j].w <= mid) {
                    int u = edges[j].u, v = edges[j].v;
                    g.Unite(u,v);
                    j++;
                }

                for(auto id:queries[mid]) {
                    int u = qr[id].u, v = qr[id].v, k = qr[id].k;
                    if(g.find_sets(u) == g.find_sets(v) && g.sz[ g.find_sets(u) ] >= k) {
                        ans[id] = oldval[mid];
                        R[id] = mid - 1;
                    }
                    else L[id] = mid + 1;
                }

                queries[mid].clear();
            }
        }

        for(int i = 1;i <= q;i++) {
            // cout << L[i] << ' ' << R[i] << '\n';
            cout << ans[i] << '\n';
            // if(ans[i] == -1) cout << ans[i] << '\n';
            // else cout << oldval[ ans[i] ] << '\n';
        }
    }
}

namespace subtask1
{
    void solve()
    {
        sort(edges.begin(),edges.end(),[] (Edge a,Edge b){return a.w < b.w;});
        while(q--) {
            int u,v,k; cin >> u >> v >> k;
            if(u == v && k == 1) {
                cout << 0 << '\n';
                continue;
            }
            g.build(n);
            int res = -1;
            for(int i = 0;i < m;i++) {
                g.Unite(edges[i].u,edges[i].v);
                if(g.find_sets(u) == g.find_sets(v) && g.sz[ g.find_sets(u) ] >= k) {
                    res = edges[i].w;
                    break;
                }
            }

            cout << res << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    sol::solve();
    return 0;   
}
