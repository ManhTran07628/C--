#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e7 + 7;


// pii egcd(ll A,ll B)
// {
//     if(B == 0) return {1,0};
//     ll k = A / B, r = A % B;
//     auto [x,y] = egcd(B,r);
//     return {-y,-x - k * y};
// }

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "balltake"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,b,c; cin >> a >> b >> c;
    if(c % __gcd(a,b) != 0) {
        cout << -1;
        return 0;
    }

    ll res = oo;
    for(ll x = 1;x <= MM;x++) {
        ll by = a * x - c;
        // cout << a * x << ' ' << by << '\n';
        if(by % b == 0 && by >= 0) {
            res = min(res,x + by / b);
        }
    }
    cout << (res == oo ? -1 : res);

    return 0;
}