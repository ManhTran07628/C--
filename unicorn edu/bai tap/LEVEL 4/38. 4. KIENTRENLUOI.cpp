#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MOD = 1e9 + 7;
int n,m;
vector<int> inv,fac;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    inv.resize(n + m + 5);
    fac.reserve(n + m + 5);
    inv[1] = 1; fac[1] = 1;
    for(int i = 2;i < n + m + 1;i++) {
        fac[i] = 1ll * fac[i-1] * 1ll * i % MOD;
        inv[i] = MOD - MOD / i * 1ll * inv[MOD % i] % MOD; // tinh nghich dao modulo
    }

    inv[0] = 1;
    for(int i = 1;i < n + m + 1;i++)
        inv[i] = 1ll * inv[i-1] * inv[i] % MOD;

    int res = 0;
    for(int k = 0;k <= min(n,m);k++) {
        ll s = (1ll * fac[n + m - k]) % MOD;
        s = (1ll * s * inv[n - k]) % MOD;
        s = (1ll * s * inv[m - k]) % MOD;
        s = (1ll * s * inv[k]) % MOD;
        res = (1ll * res + s) % MOD;
    }
    cout << res;
    return 0;
}