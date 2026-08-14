#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
ll frac[MM + 5],finv[MM];

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
    ll n; cin >> n;
    frac[0] = 1;
    for(ll i = 1;i <= MM;i++) {
        frac[i] = (frac[i - 1] * i) % MOD;
    }
    finv[MM] = binpow(frac[MM],MOD - 2);
    for(ll i = MM;i >= 1;i--) {
        finv[i - 1] = (finv[i] * i) % MOD;
    }
    // cout << frac[n * 2];
    ll res = frac[n * 2] * finv[n + 1] % MOD * finv[n] % MOD;
    cout << res;
    return 0;
}