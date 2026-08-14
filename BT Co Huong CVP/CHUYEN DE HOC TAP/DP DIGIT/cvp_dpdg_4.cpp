#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
ll L, R, dp[20][2][200], k;


ll f(int id,int tight,ll sum,string s)
{
    int n = s.size();
    if(id == n) return (sum == k);
    ll memo = dp[id][tight][sum];
    if(memo != -1) return memo;
    ll lim = !tight ? 9 : s[id] - '0';
    memo = 0;
    for(int i = 0;i <= lim;i++) {
        int new_tight = tight && i == lim;
        int new_sum = sum + i;
        memo += f(id+1,new_tight,new_sum,s);
    }
    dp[id][tight][sum] = memo;
    return memo;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> R >> k;
    memset(dp,-1,sizeof(dp));
    ll r1 = f(0,1,0,to_string(R));
    memset(dp,-1,sizeof(dp));
    ll r2 = f(0,1,0,to_string(max(0ll,L-1)));
    cout << r1 - r2 + (k == 0 && L == 0);
    return 0;
}
