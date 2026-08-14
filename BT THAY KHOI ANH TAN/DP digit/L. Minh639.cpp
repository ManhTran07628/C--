#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
int q,dp[101][34][34][34];

int f(int id,int tight,int num3,int num6,int num9,string &s)
{
    if(num3 > 33 || num6 > 33 || num9 > 33) return 0;

    if(id == s.size()) return (num3 == num6 && num6 == num9 && num3 > 0);

    int memo = dp[s.size() - id][num3][num6][num9];
    if(memo != -1 && tight == 0) return memo;
    memo = 0;

    int lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_num3 = num3 + (i == 3);
        int new_num6 = num6 + (i == 6);
        int new_num9 = num9 + (i == 9);
        memo += f(id+1,new_tight,new_num3,new_num6,new_num9,s);
        memo %= MOD;
    }
    if(tight == 0) dp[s.size() - id][num3][num6][num9] = memo;
    return memo;
}

int solve(string a)
{
    return f(0,1,0,0,0,a);
}

bool check(string s) {
    int c3 = 0, c6 = 0, c9 = 0;
    for(char c : s) {
        if(c == '3') c3++;
        if(c == '6') c6++;
        if(c == '9') c9++;
    }
    return (c3 == c6 && c6 == c9 && c3 > 0);
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
    memset(dp,-1,sizeof(dp));
    cin >> q;
    while(q--) {
        string l,r; cin >> l >> r;
        int res = (solve(r) - solve(l) + check(l)) % MOD + MOD;
        cout << res % MOD << '\n';
    }
    return 0;
}