#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n,q;
ll a[MM];
pii qr[MM];

namespace subtask1
{
    void solve()
    {
        for(int t = 1;t <= q;t++) {
            int k = qr[t].fi;
            
            int res = 0;
            for(int i = 1;i <= n;i++)
                for(int j = i + 1;j <= n;j++) {
                    if(abs(a[j - 1] - a[j]) <= k) res++;
                    else break;
                }

            cout << res << '\n';
        }
    }
}

namespace subtask3
{
    ll cur_res = 0,ans[MM];
    pii d[MM];

    ll calc(ll len)
    {
        return len * (len + 1) / 2;
    }

    struct DSU
    {
        int par[MM] = {}, sz[MM] = {}, active[MM] = {};
        void build(int u)
        {
            cur_res++;
            active[u] = 1;
            par[u] = u;
            sz[u] = 1;
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

            cur_res -= calc(sz[a]);
            cur_res -= calc(sz[b]);

            par[b] = a;
            sz[a] += sz[b];

            cur_res += calc(sz[a]);
        }
    } g;
    
    void solve()
    {
        for(int i = 2;i <= n;i++) {
            d[i].fi = abs(a[i] - a[i - 1]);
            d[i].se = i;
        }
        sort(d+2,d+n+1);
        sort(qr+1,qr+q+1);

        for(int i = 2,j = 1; j <= q; j++) {
            while(i <= n && d[i].fi <= qr[j].fi) {
                g.build(d[i].se);
                if(g.active[ d[i].se - 1 ]) g.Unite(d[i].se - 1,d[i].se);
                if(g.active[ d[i].se + 1 ]) g.Unite(d[i].se + 1,d[i].se);
                i++;
            }   
            ans[ qr[j].se ] = cur_res;
        }

        for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
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
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].fi;
        qr[i].se = i;
    }
    subtask3::solve();
    return 0;
}