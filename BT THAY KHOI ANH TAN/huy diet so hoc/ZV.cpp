#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e7+7;
ll prime[MAXN];
unordered_map<ll,ll> d,kt;
const int MOD = 1e9+7;

void min_prime()
{
    for(ll i = 2;i*i < MAXN;i++)
        if(prime[i] == 0) 
            for(ll j = i;j < MAXN;j+=i)
                if(prime[j] == 0) prime[j] = i;
    for(int i = 2;i < MAXN;i++) if(prime[i] == 0) prime[i] = i;
}

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0) {
        if(b%2==1) ans = ans * a % MOD;
        b /= 2;
        a = a*a%MOD;
    }
    return ans;
}
void factor_prime(unordered_map<ll,ll> &a,ll k)
{
    while(k > 1) {
        ll p = prime[k],cnt = 0;
        while(k % p == 0) {
            k /= p;
            cnt++;
        }
        a[p] = max(a[p],cnt);
    }
}
void result(ll &ans)
{
    for(pair<ll,ll> i:d) {
        ll power = i.se-kt[i.fi];
        if(power%2==1)power--;
        if(power > 0) ans = (ans%MOD*binpow(i.fi,power)%MOD)%MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_prime();
    int n,k;
    cin >> n >> k;
    ll val = 1;
    for(int i = 1;i <= n;i++) {
        ll a;
        cin >> a;
        if(i == k) {
            factor_prime(kt,a);
            val = a;
        }
        factor_prime(d,a);
    }
    ll ans = 1;
    result(ans);
    cout << ans;
    return 0;
}