#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,K;
string s;

string add(string a,string b)
{
    while(a.size() != b.size()) {
        if(a.size() < b.size()) a = '0' + a;
        else b = '0' + b;
    }

    int memo = 0;
    string res = "";
    for(int i = a.size() - 1;i >= 0;i--) {
        int plus = (a[i] - '0') + (b[i] - '0') + memo;
        char c = plus % 10 + '0';
        memo = plus / 10;
        res.push_back(c);
    }
    if(memo > 0) res.push_back('1');
    reverse(res.begin(),res.end());
    return res;
}

namespace subtask12
{
    string dp[101][101];

    string remove_zero(string a)
    {
        if(a[0] == '0' && a.size() == 1) return a;

        reverse(a.begin(),a.end());
        while(a.back() == '0') a.pop_back();
        reverse(a.begin(),a.end());
        return a;
    }

    bool cmp(string a,string b)
    {
        a = remove_zero(a);
        b = remove_zero(b);
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) 
            for(int j = 1;j <= K;j++) 
                dp[i][j] = '0' - 1;

        dp[0][0] = '0';
        for(int i = 1;i <= n;i++) {
            for(int k = 1;k <= min(i,K);k++) {

                string t = "";
                for(int j = i;j >= 1;j--) {
                    t = s[j] + t;
                    if(t[0] == 0 && t.size() > 0) continue;
                    if(k - 1 > j - 1) break;

                    string cost = add(dp[j - 1][k - 1],t);
                    if(cmp(dp[i][k],cost)) {
                        dp[i][k] = cost;
                    }

                }

            }
        }


        cout << dp[n][K];
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
    cin >> n >> K >> s;
    s = ' ' + s;
    subtask12::solve();
    return 0;
}