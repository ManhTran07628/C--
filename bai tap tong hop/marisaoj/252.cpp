#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll dp[13][2][130],l,r;


ll f(int id,int tight,int sum,string s,int n)
{
    if(id == n) return sum;
    ll memo = dp[id][tight][sum];
    if(memo != -1) return memo;
    int lim = !tight ? 9 : s[id] - '0';
    memo = 0;
    for(int i = 0;i <= lim;i++) {
        int newtight = tight && i == lim;
        memo += f(id+1,newtight,sum+i,s,n);
    }
    dp[id][tight][sum] = memo;
    return memo;
}


void solve()
{
    string L = to_string(l-1);
    string R = to_string(r);
    memset(dp,-1,sizeof(dp));
    ll right = f(0,1,0,R,R.size());
    memset(dp,-1,sizeof(dp));
    ll left = f(0,1,0,L,L.size());
    cout << right - left;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;
    solve();
    return 0;
}