#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 60 + 7;
const int MOD = 998244353;
ll n,a[MM],f[1 << 20];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int mask = 1;mask < (1 << n);mask++) {
        f[mask] = 1;
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                f[mask] = (f[mask] * a[i]) % MOD;
            }
        }
        f[mask] = (f[mask - 1] + f[mask]) % MOD;

    }
    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        cout << ((f[r] - f[l - 1]) % MOD + MOD) % MOD << '\n';
    }


    return 0;
}