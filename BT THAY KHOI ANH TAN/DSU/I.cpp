#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,q,vis[MM];
ll ans[MM];
pii h[MM],y[MM];

int par[MM],sz[MM];

void make_sets()
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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    make_sets();
    for(int i = 1;i <= n;i++) {
        cin >> h[i].fi;
        h[i].se = i;
    }
    for(int i = 1;i <= q;i++) {
        cin >> y[i].fi;
        y[i].se = i;
    }
    sort(h+1,h+n+1);
    sort(y+1,y+q+1);
    ll res = 0;
    for(int i = 1,j = 1;j <= q;j++) {
        while(i <= n && h[i].fi <= y[j].fi) {
            vis[ h[i].se ] = 1;
            if(vis[ h[i].se - 1 ]) {
                ll d1 = sz[ find_sets( h[i].se - 1 ) ];
                ll d2 = sz[ find_sets( h[i].se ) ];
                if(d2 == 1) d2 = 0;
                res = res - d1 * (d1 + 1) / 2 - d2 * (d2 + 1) / 2;
                Unite(h[i].se - 1, h[i].se);
                ll d3 = sz[ find_sets( h[i].se ) ];
                res += d3 * (d3 + 1) / 2;
            }
            if(vis[ h[i].se + 1 ]) {
                ll d1 = sz[ find_sets( h[i].se + 1 ) ];
                ll d2 = sz[ find_sets( h[i].se ) ];
                if(d2 == 1) d2 = 0;
                res = res - d1 * (d1 + 1) / 2 - d2 * (d2 + 1) / 2;
                Unite(h[i].se + 1, h[i].se);
                ll d3 = sz[ find_sets( h[i].se ) ];
                res += d3 * (d3 + 1) / 2;
            }
            if(!vis[ h[i].se + 1 ] && !vis[ h[i].se - 1 ]) res++;
            i++;
        }
        ans[ y[j].se ] = res;
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}