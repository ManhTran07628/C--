#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,q,h[MM],y[MM];

namespace subtask123458
{
    int L[MM],R[MM];
    void solve()
    {
        for(int t = 1;t <= q;t++) {
            int Y = y[t];

            stack<int> st2;
            h[n+1] = oo;
            st2.push(n+1);
            for(int i = n;i >= 1;i--) {
                st2.push(i);
                while(!st2.empty() && Y >= h[st2.top()]) st2.pop();
                R[i] = st2.top();
            }
            
            ll res = 0;

            for(int i = 1;i <= n;i++) {
                if(Y < h[i]) continue;
                res += R[i] - i;
            }
            cout << res << '\n';
        }
    }
}

namespace subtask67
{
    bool check()
    {
        for(int i = 2;i <= n;i++) if(h[i] < h[i-1]) return 0;
        return 1;
    }

    void solve()
    {
        for(int t = 1;t <= q;t++) {
            ll Y = y[t];
            ll pos = upper_bound(h+1,h+n+1,Y) - h - 1;
            cout << pos * (pos + 1) / 2 << '\n';
        }
    }
}

namespace sol
{
    pii qr[MM],a[MM];
    int vis[MM];
    ll res = 0,ans[MM];

    struct DSU
    {
        int par[MM] = {}, sz[MM] = {};

        void build(int a)
        {
            par[a] = a;
            sz[a] = 1;
            res++;
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
            par[b] = a;
            res -= 1ll * sz[a] * (sz[a] + 1) / 2;
            res -= 1ll * sz[b] * (sz[b] + 1) / 2;
            // cout << sz[a] << ' ' << sz[b] << '\n';
            sz[a] += sz[b];
            res += 1ll * sz[a] * (sz[a] + 1) / 2;
        }
    } g;

    void solve()
    {
        for(int i = 1;i <= q;i++) {
            qr[i] = {y[i],i};
        }
        for(int i = 1;i <= n;i++) {
            a[i] = {h[i],i};
        }

        sort(qr+1,qr+q+1,[] (pii a,pii b){
            return a.fi < b.fi;
        });

        sort(a+1,a+n+1,[] (pii a,pii b){
            return a.fi < b.fi;
        });

        for(int i = 1, j = 1; i <= q; i++) {
            while(j <= n && qr[i].fi >= a[j].fi) {
                g.build(a[j].se);
                if(vis[ a[j].se - 1 ]) g.Unite(a[j].se - 1,a[j].se);
                if(vis[ a[j].se + 1 ]) g.Unite(a[j].se,a[j].se + 1);
                vis[ a[j].se ] = 1;
                j++;
            }
            ans[ qr[i].se ] = res;
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
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= q;i++) cin >> y[i];
    // if(q <= 1e3) subtask123458::solve();
    // else subtask67::solve();
    sol::solve();
    return 0;
}