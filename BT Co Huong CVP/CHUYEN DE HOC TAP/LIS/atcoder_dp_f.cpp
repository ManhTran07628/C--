#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int dp[3001][3001],pos[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s,t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    int maxx = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(s[i] != t[j]) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            else dp[i][j] = dp[i-1][j-1] + 1;
        }

    int last_s = n + 1, last_t = m + 1;
    maxx = dp[n][m];
    vector<char> v;
    for(int i = n;i >= 1;i--)
        for(int j = m;j >= 1;j--) {
            if(dp[i][j] == maxx && i < last_s && j < last_t && s[i] == t[j]){
                v.push_back(s[i]);
                maxx--;
                last_s = i;
                last_t = j;
                // cout << i << ' ' << j << '\n';
            }
        }
    reverse(v.begin(),v.end());
    for(auto x:v) cout << x;
    return 0;
}