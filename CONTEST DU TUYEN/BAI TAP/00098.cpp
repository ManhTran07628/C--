#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;


ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll res = oo;
    ll a,b;
    cin >> a >> b;
    ll A = __gcd(a,b), B = lcm(a,b);

    ll p = a * b;
    ll r1 = oo, r2 = 0;
    int cnt = 0;
    for(ll x = sqrt(p);x >= 1;x--) {
        if(p % x == 0) {
            ll y = p / x;
            if(__gcd(x,y) == A && lcm(x,y) == B) {
                r1 = min(x,y);
                r2 = max(x,y);
                break;
            }
        }
        cnt++;
    }

    cout << r1 << ' ' << r2;
    return 0;
}
