#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll L,R;
string t;

int pi[7];
int nxt[7][200];

ll dp[20][2][2][7][2];

ll f(int id,int tight,int lead,int cur_num,int valid,string s,string cur_str)
{
    
    if(id == s.size()) {
        return valid;
    }

    ll memo = dp[id][tight][lead][cur_num][valid];
    if(memo != -1) return memo;
    memo = 0;
    ll lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);

        int new_lead = (lead && i == 0);

        int new_cur_num = (new_lead ? 0 : nxt[cur_num][i + '0']);

        int new_valid = valid | (new_cur_num == t.size());

        memo += f(id + 1,new_tight,new_lead,new_cur_num,new_valid,s,cur_str);
    }
    dp[id][tight][lead][cur_num][valid] = memo;
    return memo;
}   

ll solve(ll a)
{
    string s = to_string(a);
    memset(dp,-1,sizeof(dp));
    return f(0,1,1,0,0,s,"");
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
                // cout << i << '\n';
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
        freopen(taskname ".out","w",stdout);
    }
    cin >> L >> R >> t;

    pi[0] = 0;
    for(int i = 1;i < t.size();i++) {
        int j = pi[i - 1];
        while(j > 0 && t[i] != t[j]) j = pi[j - 1];
        if(t[i] == t[j]) j++;
        pi[i] = j;
    }

    for(int i = 0;i <= t.size();i++) {
        for(char c = '0';c <= '9';c++) {
            if(i == t.size()) {
                nxt[i][c] = t.size();
                continue;
            }

            int j = i;
            while(j > 0 && c != t[j]) j = pi[j - 1];
            if(c == t[j]) j++;

            nxt[i][c] = j;
        }
    }

    // cout << 36;
    cout << solve(R) - solve(L - 1);
    return 0;   
}