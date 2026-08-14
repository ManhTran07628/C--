#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
ll n,a[MM];
map<ll,ll> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll so = 0,se = 0, ans = 0; // so le -  se chan
    cin >> n;
    mp[0] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(i % 2) so += a[i];
        else se += a[i];
        ans += mp[se-so];
        mp[se-so]++;
    }
    cout << ans;
    return 0;
}