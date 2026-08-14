#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int t,sp[MM];

ll dp[20][1600];

ll special(ll a)
{
    int step = 500;
    while(step > 0 && a != 01) {
        string s = to_string(a);
        ll cnt = 0;
        for(auto c:s) {
            int f = c - '0';
            cnt += f * f;
        }
        a = cnt;
        step--;
    }
    return a == 1;
}

ll f(int id,int tight,int sum,string s)
{
    if(id == s.size()) return sp[sum] == 0;
    int sz = s.size() - id;
    ll memo = dp[sz][sum];
    if(memo != -1 && tight == 0) return memo;
    memo = 0;
    ll lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_sum = sum + i * i;
        memo += f(id+1,new_tight,new_sum,s);
    }
    if(tight == 0) dp[sz][sum] = memo;
    return memo;
}

ll solve(string a)
{
    return f(0,1,0,a);
}

bool valid(string s)
{
    ll cnt = 0;
    for(auto c:s) {
        int f = c - '0';
        cnt += f * f;
    }
    return !sp[cnt];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "PEARL"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i <= 1600;i++) {
        if(special(i)) {sp[i] = 1;}
    }
    cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        cout << solve(b) - solve(a) + valid(a) << '\n';
    }
    return 0;
}