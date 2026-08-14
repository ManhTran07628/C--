#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<ll,ll> x[MAXN],vt[MAXN];
ll MOD = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> x[i].fi >> x[i].se;
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll left = lower_bound(x+1,x+n+1,make_pair(x[i].fi-x[i].se,-1ll))-x;
        ll right = upper_bound(x+1,x+n+1,make_pair(x[i].fi+x[i].se,-1ll))-x;
        ll l = LLONG_MAX,r = LLONG_MIN;
        // for(int j = left;j <= right;j++) {
        //     l = min(l,)
        // }
        cout << left << ' ' << right << '\n';
    }
    cout << ans;
    // ans = (ans%MOD+(right-left)*i%MOD)%MOD;
    return 0;
}