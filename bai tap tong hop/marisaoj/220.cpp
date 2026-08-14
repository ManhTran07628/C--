#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
const int MOD = 1e9+7;
int n,newid[MM];
ll dp[1 << 15][MM],mp[1 << 15],a[MM],k;
vector<ll> primes;
void init()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        primes.push_back(a[i]);
    }
}

ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
}

void solve()
{
    sort(primes.begin(),primes.end());
    primes.erase(unique(primes.begin(),primes.end()),primes.end());
    int m = primes.size();

    for(int i = 0;i < m;i++) newid[ primes[i] ] = i;
    for(int mask = 1;mask < (1 << m);mask++) {
        ll cnt = 1;
        for(int i = 0;i < m;i++) {
            if(mask >> i & 1) {
                cnt = lcm(cnt,primes[i]*1ll);
            }
        }
        // cout << mask << ' ' << cnt << '\n';
        mp[mask] = cnt;
    }
    // for(int i = 1;i < m;i++) 
    //     dp[1 << i][1] = 1;
    for(int i = 0;i <= n;i++) dp[0][i] = 1;

    for(int j = 1;j <= n;j++) {
        for(int mask = 1;mask < (1 << m);mask++) {
            dp[mask][j] = dp[mask][j-1];
            if( !(mask >> newid[ a[j] ] & 1) ) continue;
            int p_mask = mask ^ (1 << newid[ a[j] ]);
            if(mp[mask] <= k) {
                dp[mask][j] = (dp[mask][j] + dp[mask][j-1]) % MOD;
                dp[mask][j] = (dp[mask][j] + dp[p_mask][j-1]) % MOD;
            }
            
        }
    }

    ll ans = 0;
    for(int mask = 1;mask < (1 << m);mask++) {
        ans = (ans + dp[mask][n]) % MOD;
    }
    cout << ans;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}