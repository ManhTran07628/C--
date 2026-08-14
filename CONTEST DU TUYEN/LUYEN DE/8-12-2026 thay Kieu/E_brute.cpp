#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
ll L,R;
string t;

ll dp[20][2][7][2];

ll f(int id,int tight,int cur_num,int valid,string s,string cur_str)
{
    
    if(id == s.size()) {
        // if(cur_str != "")
            // cout << cur_str << ' ' << cur_num << ' ' << valid << '\n';
        return valid;
    }

    
    ll memo = dp[id][tight][cur_num][valid];
    if(memo != -1) return memo;
    memo = 0;
    ll lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        if(i == t[cur_num] - '0') {
            int new_cur_num = cur_num + (i == t[cur_num] - '0');
            int new_valid = (valid | (new_cur_num == t.size()) );
            memo += f(id + 1,new_tight,new_cur_num,new_valid,s,cur_str + char(i + '0'));
            memo %= MOD;
        }
        else {
            memo += f(id + 1,new_tight,0,valid,s,cur_str + char(i + '0'));
            memo %= MOD;
        }
    }
    dp[id][tight][cur_num][valid] = memo;
    return memo;
}   

ll solve(ll a)
{
    string s = to_string(a);
    memset(dp,-1,sizeof(dp));
    return f(0,1,0,0,s,"");
}

namespace subtask1
{
    bool check(string a,string b)
    {
        int sza = a.size() - 1, szb = b.size() - 1;
        for(int i = 0;i + szb <= sza;i++) {
            bool ok = 1;
            for(int j = i;j <= i + szb;j++) {
                if(a[j] != b[j - i]) ok = 0;
                // cout << j << ' ' << j - i << ' ' << a[j] << ' ' << b[j - i] << '\n';
            }
            // cout << '\n';
            if(ok) return 1;
        }
        return 0;
    }

    void solve()
    {
        // cout << check("100","2");
        int res = 0;
        for(int i = L;i <= R;i++) {
            if(check(to_string(i),t)) {
                res++;
                cout << i << '\n';
            }
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "E"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".ans","w",stdout);
    }
    cin >> L >> R >> t;
    // cout << solve(R);
    // cout << solve(R) - solve(L - 1);
    subtask1::solve();
    return 0;   
}