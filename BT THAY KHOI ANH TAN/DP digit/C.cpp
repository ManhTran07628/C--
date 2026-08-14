#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
string L,R;
ll x;
ll dp[101][2][901];

ll f(int id,int tight,int sum,string s)
{
    if(id == s.size()) return sum;
    ll memo = dp[id][tight][sum];
    if(memo != -1) return memo;
    memo = 0;
    int lim = (!tight ? 9 : s[id] - '0');
    for(int i = 0;i <= lim;i++) {
        int new_tight = tight && i == lim;
        int new_sum = sum + i;
        memo += f(id+1,new_tight,new_sum,s);
        memo %= MOD;
    }
    dp[id][tight][sum] = memo;
    return memo;
}

ll solve(string s)
{
    memset(dp,-1,sizeof(dp));
    return f(0,1,0,s);
}

ll sumdigit(string s)
{
    ll sum = 0;
    for(auto c:s) {
        sum += c - '0';
    }
    return sum;
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
    cin >> L >> R;
    ll res = (solve(R) - solve(L) + sumdigit(L)) % MOD + MOD;
    cout << res % MOD;
    return 0;
}