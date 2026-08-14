#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
ll dp[13][2][118][118],a,b,k,t;
// dp[id][tight][sum][nums];


ll f(int id,int tight,int sum,int nums,string s)
{
    int n = s.size();
    if(id == n) return (sum == 0 && nums == 0);

    ll memo = dp[id][tight][sum][nums];
    if(memo != -1) return memo;

    int lim = !tight ? 9 : s[id] - '0';
    memo = 0;
    for(int i = 0;i <= lim;i++) {
        int new_tight = tight && i == lim;
        int new_sum = (sum+i) % k;
        int new_nums = (nums*10+i) % k;
        memo += f(id+1,new_tight,new_sum,new_nums,s);
    }
    dp[id][tight][sum][nums] = memo;
    return memo;
}


void solve()
{
    cin >> a >> b >> k;
    if(k > 117) {
        cout << 0 << '\n';
        return;
    }
    string l = to_string(a-1), r = to_string(b);
    memset(dp,-1,sizeof(dp));
    ll R = f(0,1,0,0,r);
    memset(dp,-1,sizeof(dp));
    ll L = f(0,1,0,0,l);
    cout << R-L << '\n';
    memset(dp,-1,sizeof(dp));
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