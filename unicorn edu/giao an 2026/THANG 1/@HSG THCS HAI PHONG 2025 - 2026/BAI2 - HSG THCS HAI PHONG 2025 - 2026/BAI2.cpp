#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll n,a[MM],ps[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll res = -oo;
    for(int i = 1;i <= n;i++) {
        ps[i] = max(a[i],ps[i-1] + a[i]);
        res = max(res,ps[i]);
    }
    cout << res;
    return 0;
}