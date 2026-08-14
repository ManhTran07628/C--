#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<ll,ll>
const int MM = 1e5+7;
int n;
pii a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1, [] (pii a,pii b){
        return a.se > b.se;
    });
    ll res = 0,time = 0;
    for(int i = 1;i <= n;i++) {
        res += time * a[i].se;
        time += a[i].fi * 2;
        // cout << time << ' ' << res << '\n';
    }
    cout << res;
    return 0;
}