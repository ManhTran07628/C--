#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll dp[20][2][11][2],a,b;
string num;


ll backtrack(ll pos,ll tight,ll prev,ll zero)
{
    if(pos == num.size()) return 1;
    ll res = dp[pos][tight][prev][zero];
    if(res != -1) return res;
    res = 0;
    ll limit = tight ? num[pos]-'0' : 9;
    for(ll d = 0;d <= limit;d++) {
        if(!zero && d == prev) continue;
        ll newtight = tight && (d == limit);
        ll newzero = zero && (d == 0);
        res += backtrack(pos+1,newtight,d,newzero);
    }
    dp[pos][tight][prev][zero] = res;
    return res;
}

ll solve(ll x)
{
    num = to_string(x);
    memset(dp,-1,sizeof(dp));
    return backtrack(0,1,10,1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    // cout << a << ' ' << b << '\n';
    cout << solve(b) - solve(a-1);
    return 0;
}