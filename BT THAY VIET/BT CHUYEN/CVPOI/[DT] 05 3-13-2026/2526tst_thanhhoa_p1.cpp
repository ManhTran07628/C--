#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 3e18
const int MM = 3e5 + 7;
ll n;
pair<ll,ll> x[MM],d[MM];

bool check(ll T)
{
    ll max_u = -oo,min_u = oo,max_v = -oo,min_v = oo;
    for(int i = 1;i <= n;i++) {
        max_u = max(max_u,d[i].fi);
        min_u = min(min_u,d[i].fi);
        max_v = max(max_v,d[i].se);
        min_v = max(min_v,d[i].se);
    }
    if(max_u - T <= min_u + T && max_v - T <= min_v + T) {
        ll length_u = min_u + T - max_u + T;
        ll length_v = min_v + T - max_v + T;
        if(length_u >= 2 || length_v >= 2) return 1;
        if((length_u + length_v) % 2 == 0) return 1;
    }
    return 0;
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> x[i].fi >> x[i].se;
        d[i] = {x[i].fi + x[i].se,x[i].fi - x[i].se};
    }
    ll L = 0,R = 3e18,res = 0;
    while(L <= R) {
        ll mid = (L + R) / 2;
        if(check(mid)) {
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << res;

    return 0;
}