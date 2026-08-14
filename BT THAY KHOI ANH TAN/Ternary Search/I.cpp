#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
ll t,n,a,b;

ll f(ll k)
{
    return b * k - k*(k-1)/2 + (n-k) * a;
}

void solve()
{
    ll l = 0,r = min(n,b),ans = 0;
    while(l <= r) {
        ll m1 = l + (r-l) / 3,m2 = r - (r-l) / 3;
        if(f(m1) > f(m2)) {
            ans = m1;
            r = m2 - 1;
        }
        else {
            ans = m2;
            l = m1 + 1;
        }
    }
    cout << f(ans);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        solve();
        cout << '\n';
    }
    return 0;   
}