#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll a,b,n;
ll sum(ll l,ll r)
{
    ll ans = 0;
    while(l <= r) {
        ll val = n / l;
        ll st = l,endd = n / val;
        if(endd > r) endd = r;
        ans += (endd-st+1)*val;
        l = endd+1;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    cout << sum(1,b) - sum(1,a-1);
    return 0;
}