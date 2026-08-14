#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 20;
int t;
ll dp[MM][2][11];

ll f(int id,int tight,int lead,int num,const string &s)
{
    if(id == s.size()) return 1;

    int l = s.size() - id;

    ll memo = dp[l][lead][num];
    if(memo != -1 && tight == 0) return memo;
    memo = 0;

    int lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        if(i == num) continue;
        int new_tight = (tight && i == lim);
        int new_lead = (lead && i == 0);
        if(i == 0) {
            if(lead == 1) {
                memo += f(id+1,new_tight,new_lead,num,s);
            }
            else {
                memo += f(id+1,new_tight,new_lead,i,s);
            }
        }
        else {
            memo += f(id+1,new_tight,new_lead,i,s);
        }
    }
    if(tight == 0) dp[l][lead][num] = memo;
    return memo;
}

ll solve(string a)
{
    return f(0,1,1,10,a);
}

int check(string s){
    for(int i = 1; i < s.size(); i++) if(s[i] == s[i - 1]) return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BAI1"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    memset(dp,-1,sizeof(dp));
    cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        cout << solve(b) - solve(a) + check(a) << '\n';
    }
    return 0;
}