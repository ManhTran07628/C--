#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
int n,q,a[MM],qr[MM];
map<int,int> cnt,cntfreq;
ll ans[MM],finv[MM],f[MM];

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
    #define taskname "BEQUAL"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }

    f[0] = 1;
    for(int i = 1;i < MM;i++) f[i] = (f[i-1] * 1ll * i) % MOD;
    finv[MM - 1] = binpow(f[MM - 1],MOD - 2);
    for(int i = MM - 1;i >= 1;i--) 
        finv[i - 1] = (finv[i] * 1ll * i) % MOD;

    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[ a[i] ]++;
    }
    for(auto x:cnt) {
        cntfreq[x.se]++;
    }
    for(int i = 1;i <= q;i++) {
        cin >> qr[i];
        int x = qr[i];
        ll res = 0;
        for(auto c:cntfreq) {
            if(c.fi < x) continue;
            ll cntf = c.se;
            ll cur_res = f[c.fi] * finv[x] % MOD * finv[c.fi - x] % MOD * cntf % MOD;
            res = (res + cur_res) % MOD;
        }
        cout << res << '\n';
    }

    return 0;
}