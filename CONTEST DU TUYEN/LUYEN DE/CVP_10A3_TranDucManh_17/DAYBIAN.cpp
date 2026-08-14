#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
ll n,k,a[MM];
map<ll,ll> mp;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "DAYBIAN"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    ll sum = 0,res = 0;
    mp[0] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
        res += mp[sum - k];
        mp[sum]++;
    }
    cout << res;
    return 0;
}