#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,q,t; 
ll x[MM],y[MM];
ll psx[MM],psy[MM];

ll calc(ll x,ll a[],ll ps[])
{
    int pos = upper_bound(a+1,a+n+1,x) - a - 1;
    ll d1 = x * pos - ps[pos];
    ll d2 = (ps[n] - ps[pos]) - x * (n - pos);

    // cout << pos << ' ' << a[pos] << ' ' << d1 << ' ' << d2 << '\n';
    return d1 + d2;
}

void solve1()
{
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);

    for(int i = 1;i <= n;i++) {
        psx[i] = psx[i - 1] + x[i];
        psy[i] = psy[i - 1] + y[i];
    }

    while(q--) {
        int u,v; cin >> u >> v;
        ll res = calc(u,x,psx) + calc(v,y,psy);
        cout << res << '\n';
    }
}

void solve2()
{
    for(int i = 1;i <= n;i++) {
        ll u = x[i] + y[i];
        ll v = x[i] - y[i];
        x[i] = u;
        y[i] = v;
    }

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);

    for(int i = 1;i <= n;i++) {
        psx[i] = psx[i - 1] + x[i];
        psy[i] = psy[i - 1] + y[i];

        // cout << x[i] << ' ' << y[i] << '\n';
    }

    while(q--) {
        ll u,v; cin >> u >> v;
        // u *= 2; v *= 2;
        ll res = calc(u + v,x,psx) + calc(u - v,y,psy);
        cout << res / 2 << '\n';
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
    cin >> n >> q >> t;
    for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    if(t == 1) solve1();
    else solve2();
    return 0;
}