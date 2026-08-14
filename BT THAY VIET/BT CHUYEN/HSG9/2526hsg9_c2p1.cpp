#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
ll a[4],d;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a[1] >> a[2] >> a[3] >> d;
    ll ans = oo;
    ll d1 = abs(a[3] - a[1] - a[2]);
    if(d1 >= d) ans = min(ans,d1 - d);
    else ans = 0;
    ll d2 = abs(a[2] - a[1] - a[3]);
    if(d2 >= d) ans = min(ans,d2 - d);
    else ans = 0;
    ll d3 = abs(a[1] - a[2] - a[3]);
    if(d3 >= d) ans = min(ans,d3 - d);
    else ans = 0;
    cout << ans;
    return 0;
}