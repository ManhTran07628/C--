#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    ll cnt = 0,res = n * m - (k - 1),ans = 1;
    for(ll a = 1;a <= m;a++) {
        ll b = min(n, res / a);
        ans = max(ans,a*b);
    }
    cout << ans;
    return 0;
}