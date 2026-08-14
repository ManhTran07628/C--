#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
ll dp[20][2][3],n;
string s;
// dp[idx][tight][state]


ll f(int id,int tight,int state)
{
    if(id == n) return state == 2;
    ll memo = dp[id][tight][state];

    if(memo != -1) return memo;
    int lim = !tight ? 9 : s[id] - '0';
    memo = 0;

    for(int i = 0;i <= lim;i++) {
        int new_state = state;
        if(state == 2) {
            new_state = 2;
        } else if(state == 0) {
            if(i == 1) new_state = 1;
            else if(i == 4) new_state = 2;
            else new_state = 0;
        } else if(state == 1) {
            if(i == 3) new_state = 2;
            else if(i == 1) new_state = 1;
            else if(i == 4) new_state = 2;
            else new_state = 0;
        }
        memo += f(id+1,tight && i == lim,new_state);
    }
    dp[id][tight][state] = memo;
    return memo;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    cout << f(0,1,0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    solve();
    return 0;
}