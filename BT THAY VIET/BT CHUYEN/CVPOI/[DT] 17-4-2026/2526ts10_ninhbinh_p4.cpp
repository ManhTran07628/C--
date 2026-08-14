#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll a,b;
ll dp[17][2][11][2][2];    

ll f(int id,int tight,int last_num,int state,int start,string s)
{
    if(id == s.size()) return state;

    ll &memo = dp[id][tight][last_num][state][start];
    if(memo != -1) return memo;

    memo = 0;
    int lim = (tight ? s[id] - '0' : 9);

    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_state = (state && last_num >= i);
        if(i == 0 && !start) {
            int new_start = 1;
            memo += f(id + 1,new_tight,10,new_state,0,s);
        }
        else {
            if(!start || i <= last_num) memo += f(id + 1,new_tight,i,new_state,1,s);
        }
    }
    return memo;
}

ll solve(ll x)
{
    string X = to_string(x);
    memset(dp,-1,sizeof(dp));
    return f(0,1,10,1,0,X);
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
    cin >> a >> b;
    cout << solve(b) - solve(a-1);
    return 0;
}