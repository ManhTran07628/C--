#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
ll n,sz;
string p;

namespace subtask1
{
    ll res = 0;

    bool check(string s)
    {
        for(int i = 0;i + sz - 1 < s.size();i++) {
            bool ok = 1;
            for(int j = i;j <= i + sz - 1;j++) {
                if(s[j] != p[j - i]) ok = 0;
            }
            if(ok) return 0;
        }
        return 1;
    }

    void dfs(int id,string s)
    {
        if(id > n) {
            // cout << s << '\n';
            res += check(s);
            return;
        }

        for(int i = 0;i <= 9;i++) {
            dfs(id + 1,s + char(i + '0'));
        }
    }

    void solve()
    {
        dfs(1,"");
        cout << res;
    }
}

namespace subtask2
{
    int dp[MM][51];

    int f(int id,int cur_cnt,string trace)
    {
        if(cur_cnt >= sz) {
            return 0;
        }
        if(id > n) {
            // cout << trace << ' ' << cur_cnt << '\n';
            return 1;
        }
        int memo = dp[id][cur_cnt];
        if(memo != -1) return memo;
        memo = 0;
        for(int i = 0;i <= 9;i++) {
            int new_cnt = cur_cnt + (i == p[cur_cnt] - '0');
            if(i == p[cur_cnt] - '0') {
                if(new_cnt >= sz) continue;
                memo = (memo % MOD + f(id+1,new_cnt,trace + char(i + '0')) % MOD) % MOD;
            }
            else {
                new_cnt = 0;
                if(i == p[new_cnt] - '0') new_cnt++;
                memo = (memo % MOD + f(id+1,new_cnt,trace + char(i + '0')) % MOD) % MOD;
            }
        }
        dp[id][cur_cnt] = memo % MOD;
        return memo;
    }

    ll get()
    {
        memset(dp,-1,sizeof(dp));
        return f(1,0,"");
    }

    void solve()
    {
        cout << get();
    }
}

namespace subtask3
{
    ll binpow(ll a,ll b)
    {
        if(b == 0) return 1;
        ll x = binpow(a,b / 2);
        if(b % 2 == 1) return x % MOD * x % MOD * a % MOD;
        return x * x % MOD;
    }

    void solve()
    {
        cout << binpow(9,n);
    }
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
    cin >> n >> p;
    sz = p.size();
    if(n <= 6) subtask1::solve();
    else if(sz == 1) subtask3::solve();
    else subtask2::solve();
    return 0;
}