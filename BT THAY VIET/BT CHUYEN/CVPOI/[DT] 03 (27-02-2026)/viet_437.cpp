#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,x[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> x[i];

    ll res = oo;
    for(int i = 1;i <= n;i++) {
        int h = x[i];
        ll sum = 0;
        for(int j = 1;j <= n;j++) {
            sum += abs(x[j] - (h - abs(i - j) ) );
        }
        res = min(res,sum);
    }
    cout << res;

    return 0;
}