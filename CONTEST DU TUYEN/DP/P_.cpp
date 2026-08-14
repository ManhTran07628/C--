#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e4 + 7;
const int MOD = 1e9 + 7;
string s;
int d,n;
ll dp[MM][2][101];

ll f(int id,int tight,int sum,int d)
{
    if(id == n) return (sum == 0);
    ll memo = dp[id][tight][sum];
    if(memo != -1) return memo;
    memo = 0;
    int lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_sum = (sum + i) % d;
        memo += f(id+1,new_tight,new_sum,d);
        memo %= MOD;
    }
    dp[id][tight][sum] = memo;
    return memo;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> d;
    memset(dp,-1,sizeof(dp));
    n = s.size();
    cout << f(0,1,0,d) - 1;
    return 0;
}