#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
string l,r;
int k,p;
ll dp[101][2][2][101];


ll f(int id,int tight,int lead,int cnt,string s)
{
    if(id == s.size()) return cnt <= k;
    ll memo = dp[id][tight][lead][cnt];
    if(memo != -1) return memo;
    memo = 0;
    ll lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_lead = (lead && i == 0);
        int new_cnt = cnt + (p == i);
        if(i == 0) {
            if(lead == 0) {
                memo += f(id+1,new_tight,new_lead,new_cnt,s);
                memo %= MOD;
            }
            else {
                memo += f(id+1,new_tight,new_lead,0,s);
                memo %= MOD;
            }
        }
        else {
            memo += f(id+1,new_tight,new_lead,new_cnt,s);
            memo %= MOD;
        }
    }
    dp[id][tight][lead][cnt] = memo;
    return memo;
}

ll solve(string a)
{
    memset(dp,-1,sizeof(dp));
    return f(0,1,1,0,a);
}

ll cnt(string a)
{
    int cur = 0;
    for(auto c:a) cur += ((c - '0') == p);
    return cur <= k;
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
    cin >> l >> r >> k >> p;
    if(l == r && l == "0" && p == 0 && 1 <= k) {
        cout << 1;
        return 0;
    }
    ll res = (solve(r) - solve(l) + cnt(l)) % MOD + MOD;
    cout << res % MOD;
    return 0;
}