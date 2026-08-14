#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int offset = 4500;
const int MOD = 1e9 + 7;
string l,r;
bool prime[MM];
ll dp[101][2][2][3][20001];

void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
}

ll f(int id,int tight,int lead,int state,int dif,string s)
{
    if(id == s.size()) {
        if(dif > 0 && prime[dif]) return 1;
        return 0;
    }

    ll memo = dp[id][tight][lead][state][dif + offset];
    if(memo != -1) return memo;
    memo = 0;

    int lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        int new_lead = (lead && i == 0);
        if(i == 0) {
            if(lead == 1) {
                memo += f(id+1,new_tight,new_lead,state,dif,s);
                memo %= MOD;
            }
            else {
                int new_state, new_dif = dif;
                if(state == 2) {
                    new_state = (s.size() - id) % 2;
                    if(new_state == 0) new_dif += i;
                    else new_dif -= i;
                    memo += f(id+1,new_tight,new_lead,new_state ^ 1,new_dif,s);
                    memo %= MOD;
                }
                else {
                    if(state == 0) new_dif += i;
                    else new_dif -= i;
                    memo += f(id+1,new_tight,new_lead,state ^ 1,new_dif,s);
                    memo %= MOD;
                }
            }
        }
        else {
            int new_state, new_dif = dif;
            if(state == 2) {
                new_state = (s.size() - id) % 2;
                if(new_state == 0) new_dif += i;
                else new_dif -= i;
                memo += f(id+1,new_tight,new_lead,new_state ^ 1,new_dif,s);
                memo %= MOD;
            }
            else {
                if(state == 0) new_dif += i;
                else new_dif -= i;
                memo += f(id+1,new_tight,new_lead,state ^ 1,new_dif,s);
                memo %= MOD;
            }
        }
    }
    dp[id][tight][lead][state][dif + offset] = memo;
    return memo;
}

int check(string s)
{
    int sum = 0;
    for(int j = s.size() - 1,st = 1;j >= 0;j--,st++) 
        sum += (st % 2 == 1 ? -(s[j] - '0') : s[j] - '0');
    if(sum > 0 && prime[sum]) return 1;
    return 0;
}

ll solve(string s)
{
    memset(dp,-1,sizeof(dp));
    return f(0,1,1,2,0,s);
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
    sieve();
    cin >> l >> r;
    ll res = (solve(r) - solve(l) + check(l)) % MOD + MOD;
    cout << res % MOD;
    return 0;
}