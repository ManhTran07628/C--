#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int t;
ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "THUTHACH"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    while(t--) {
        ll K,a,b; cin >> K >> a >> b;
        ll L = 1, R = 1e12, res = 0;
        while(L <= R) {
            ll mid = (L + R) / 2;
            ll cnt = mid - mid / a - mid / b + mid / lcm(a,b);
            if(cnt >= K) {
                res = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        cout << res << '\n';
    }
    return 0;
}