#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll x,L,R,S;
ll dp[20][2];


ll f(int id,int tight,ll y,string s)
{
    int n = s.size();
    if(id == n) {
        return (x ^ y) <= S; 
    }
    ll memo = dp[id][tight];
    if(memo != -1) return memo;
    ll lim = !tight ? 9 : s[id] - '0';
    memo = 0;
    for(int i = 0;i <= lim;i++) {
        int new_tight = tight && i == lim;
        memo += f(id+1,new_tight,y*10+i,s);
    }
    dp[id][tight] = memo;
    return memo;
}

void solve()
{
    string l = to_string(L-1), r = to_string(R);
    memset(dp,-1,sizeof(dp));
    L = f(0,1,0,l);
    memset(dp,-1,sizeof(dp));
    R = f(0,1,0,r);
    cout << R-L;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> L >> R >> S;
    solve();
    return 0;
}