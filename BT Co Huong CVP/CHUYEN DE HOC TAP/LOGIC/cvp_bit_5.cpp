#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int MOD = 1e9 + 7;
const int LOG = 31;
ll t,n,a[MM],cnt[MM];

ll binpow(ll a,ll b)
{
    ll res = 1;
    while(b > 0) {
        if(b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int j = LOG;j >= 0;j--) cnt[j] = 0;

        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            for(int j = LOG;j >= 0;j--)
                if(a[i] >> j & 1) cnt[j]++;
        }
        ll res = 0;
        for(int j = LOG;j >= 0;j--) {
            res += (1ll << j) * (binpow(2,cnt[j]) - 1);
            res %= MOD;
        }
        cout << res << '\n';
    }
    return 0;
}