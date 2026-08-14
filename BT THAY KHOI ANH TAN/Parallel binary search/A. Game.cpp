#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n,m,q;
int a[MM],L[MM],R[MM],ans[MM],par[MM];
vector<int> query[MM],comp[MM];
vector<pair<int,int>> edges;

int find_set(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_set(par[a]);
}

void Unite(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    par[b] = a;
}

void Pbins()
{
    while(1) {
        bool ok = 1;

        for(int i = 1;i <= m;i++) {
            if(L[i] > R[i]) continue;

            ok = 0;
            query[ (L[i] + R[i]) / 2 ].push_back(i);
        }

        if(ok) break;
        
        for(int i = 1;i <= n;i++) par[i] = i;

        for(int i = 0;i <= q;i++) {
            if(i > 0) Unite(edges[i-1].fi, edges[i-1].se);
            for(auto id : query[i]) {
                int p = 0;
                bool check = 1;

                for(auto x : comp[id]) {
                    if(p == 0) p = find_set(x);

                    if(p != find_set(x)) {
                        check = 0;
                        break;
                    }
                }

                if(check) {
                    R[id] = i - 1;
                    ans[id] = i;
                }
                else L[id] = i + 1;
            }

            query[i].clear();
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        comp[ a[i] ].push_back(i);
    }

    for(int i = 1;i <= q;i++) {
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    for(int i = 1;i <= m;i++) {
        L[i] = 0; R[i] = q; ans[i] = -1;
    }
    Pbins();
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';

    return 0;
}