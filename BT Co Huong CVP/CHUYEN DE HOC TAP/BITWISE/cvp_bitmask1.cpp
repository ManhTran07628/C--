#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int LOG = 31;
int n,a[MM];
ll cnt[LOG + 5][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    ll res = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = LOG;j >= 0;j--) {
            if(a[i] >> j & 1) res += (1ll * (1 << j) * cnt[j][0]);
            else res += (1ll * (1 << j) * cnt[j][1]);
        }

        for(int j = LOG;j >= 0;j--) {
            if(a[i] >> j & 1) cnt[j][1]++;
            else cnt[j][0]++;
        }
    }
    cout << res;
    return 0;
}