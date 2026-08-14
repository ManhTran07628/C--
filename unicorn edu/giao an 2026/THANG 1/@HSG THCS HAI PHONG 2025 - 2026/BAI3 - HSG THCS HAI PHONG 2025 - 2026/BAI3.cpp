#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll a[MM];
map<ll,ll> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k; cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; a[i] = (a[i] % k + k) % k;
    }
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        res += mp[ (k - a[i]) % k ];
        mp[ a[i] ]++;
    }
    cout << res;

    return 0;
}