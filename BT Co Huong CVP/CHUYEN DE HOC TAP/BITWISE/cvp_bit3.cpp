#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int LOG = 30;
ll n,a[MM],cnt[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        for(int j = LOG;j >= 0;j--) {
            if(a[i] >> j & 1)
                res += (1ll * (1 << j) * cnt[j]);
        }

        for(int j = LOG;j >= 0;j--)
            if(a[i] >> j & 1) cnt[j]++;
    }
    cout << res;
    return 0;
}