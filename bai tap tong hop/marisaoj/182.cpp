#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
int n,k;
ll f[MM],frac[MM];
ll a[MM];

ll binpow(ll a,ll b)
{
    if(b == 0) return 1;
    ll x = binpow(a,b / 2);
    if(b % 2 == 1) return x * x % MOD * a % MOD;
    return x * x % MOD;
}

ll C(int k,int n)
{
    return (f[n] * frac[n - k] % MOD * frac[k]) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    f[0] = 1;
    for(int i = 1;i < MM;i++) f[i] = (f[i - 1] * i) % MOD;
    frac[MM - 1] = binpow(f[MM - 1],MOD - 2);
    for(int i = MM - 1;i >= 1;i--)
        frac[i - 1] = (frac[i] * i) % MOD;    

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1,greater<ll>());
    ll res = 0, m = n;
    for(int i = 1;i <= n;i++) {
        if(k - 1 > m) break;
        // cout << k << ' ' << m << '\n';
        ll cnt = (C(k - 1,--m) + MOD) % MOD;
        // cout << cnt << '\n';
        res += cnt * a[i] % MOD;
        res %= MOD;
    }
    cout << res;
    return 0;
}