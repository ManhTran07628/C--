#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MOD = 1e9 + 7;
string L,R;
ll dp[101][2][2][2];
// dp[id][tight][leading][state]


ll f(int id,int tight,int leading,int state,string s)
{
    if(id == s.size()) return 1;
    ll memo = dp[id][tight][leading][state];
    if(memo != -1) return memo;
    memo = 0;
    ll lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_leading = (leading && i == 0);
        if(i == 0) {
            if(leading == 0) {
                if(i % 2 == state) memo += f(id + 1,new_tight,new_leading,state ^ 1,s);
                memo %= MOD;
            }
            else {
                memo += f(id + 1,new_tight,new_leading,state,s);
                memo %= MOD;
            }
        }
        else {
            if(i % 2 == state) memo += f(id + 1,new_tight,new_leading,state ^ 1,s);
            memo %= MOD;
        }
    }
    dp[id][tight][leading][state] = memo;
    return memo;
}


ll solve(string s)
{
    memset(dp,-1,sizeof(dp));
    return f(0,1,1,1,s);
}

bool check(string s)
{
    for(int i = 0;i < s.size();i++) {
        if((i + 1) % 2 != (s[i] - '0') % 2) return 0;
    }
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