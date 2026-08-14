#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll a,b;
ll dp[20][2][200];

ll f(int id,int tight,ll sum,string s)
{
    int n = s.size();
    if(id == n) return sum;
    ll memo = dp[id][tight][sum];
    if(memo != -1) return memo;

    int lim = !tight ? 9 : s[id] - '0';
    memo = 0;

    for(int i = 0;i <= lim;i++) {
        int new_tight = tight && i == lim;
        ll new_sum = sum + i;
        memo += f(id+1,new_tight,new_sum,s);
    }
    dp[id][tight][sum] = memo;
    return memo;
}

void solve()
{
    string L = to_string(a-1), R = to_string(b);
    memset(dp,-1,sizeof(dp));
    ll Left = f(0,1,0,L);
    memset(dp,-1,sizeof(dp));
    ll Right = f(0,1,0,R);
    cout << Right - Left << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;// = 1;
    cin >> t;
    while(t--) 
    {
        cin >> a >> b;
        solve();
    }
    return 0;
}