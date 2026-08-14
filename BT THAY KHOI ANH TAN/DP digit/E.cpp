#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
string L,R;
ll dp[101][2][2][15];

ll f(int id,int tight,int lead,int prev,string s)
{
    if(id == s.size()) return 1;
    ll memo = dp[id][tight][lead][prev];
    if(memo != -1) return memo;
    memo = 0;
    ll lim = (!tight ? 9 : s[id] - '0');
    for(int i = 0;i <= lim;i++) {
        if(i == prev) continue;
        int new_tight = (tight && i == lim);
        int new_lead = (lead && i == 0);
        if(i == 0) {
            if(lead == 0) {
                memo += f(id+1,new_tight,new_lead,i,s);
                memo %= MOD;
            }
            else {
                memo += f(id+1,new_tight,new_lead,prev,s);
                memo %= MOD;
            }
        }
        else {
            memo += f(id+1,new_tight,new_lead,i,s);
            memo %= MOD;
        }
    }
    dp[id][tight][lead][prev] = memo;
    return memo;
}

ll solve(string a)
{
    memset(dp,-1,sizeof(dp));
    return f(0,1,1,13,a);
}

bool check(string a)
{
    for(int i = 1;i < a.size();i++) 
        if(a[i] == a[i-1]) return 0;
    return 1;
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
    ll res = (solve(R) - solve(L) + check(L)) % MOD + MOD;
    cout << res % MOD;
    return 0;
}