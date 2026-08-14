#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 101+7;
const int MOD = 1000000007;
int t,n,m;
bool chk[11];
ll dp[107][10][1 << 10];


ll f(int id,int digit,int mask)
{
    if(id == m) return 0;
    ll memo = 0;
    if(dp[id][digit][mask] != -1) return dp[id][digit][mask];
    if(__builtin_popcount(mask) == n) memo = (memo+1) % MOD;


    if(digit + 1 <= n-1) {
        int newmask = mask | (1 << (digit+1));
        memo += f(id+1,digit+1,newmask);
        memo %= MOD;
    }
    if(digit - 1 >= 0) {
        int newmask = mask | (1 << (digit-1));
        memo += f(id+1,digit-1,newmask);
        memo %= MOD;
    }

    dp[id][digit][mask] = memo;
    return memo;
}



void solve()
{
    cin >> n >> m;  
    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    for(int i = 1;i <= n-1;i++) {
        ans += f(0,i,1 << i);
        ans %= MOD;
    }
    cout << ans << '\n';
    // f(0,1,)
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}