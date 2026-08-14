#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll p[MAXN];
vector<ll> primes;
unordered_map<ll,ll> lt;
ll MOD = 1e9+7;
void sieve()
{
    fill(p+1,p+MAXN+1,1);
    p[0] = p[1] = 0;
    for(int i = 2;i*i < MAXN-1;i++)
        if(p[i])
            for(int j = i*2;j < MAXN-1;j+=i)
                p[j] = 0;
    for(int i = 2;i < MAXN-1;i++) if(p[i]) primes.push_back(i);
}

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0) {  
        if(b%2==1) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll k;
        cin >> k;
        for(int prime:primes) {
            if(k < prime*prime*1ll) break;
            ll cnt = 0;
            while(k % prime == 0) {
                cnt++;
                k /= prime;
            }
            if(cnt > 0) lt[prime] = max(lt[prime],cnt);
        }
        // cout << k << '\n';
        if(k > 1) lt[k] = max(lt[k],1ll);
    }
    ll ans = 1;
    for(auto i:lt) {
        ll t = binpow(i.fi,i.se);
        ans = (ans%MOD*t%MOD)%MOD;
    }
    cout << ans;
    return 0;
}