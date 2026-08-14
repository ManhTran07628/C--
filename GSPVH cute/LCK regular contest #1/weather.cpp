#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
ll dp[MM];
map<string,int> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "weather"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    mp["N"] = 1;
    mp["E"] = 2;
    mp["W"] = 3;
    mp["S"] = 4;
    mp["NW"] = 5;
    mp["WS"] = 6;
    mp["SE"] = 7;
    mp["EN"] = 8;
    mp[" "] = 0;


    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        string t; t = s[i-1]; t.push_back(s[i]);
        dp[i] = (dp[i] + dp[i-1]) % MOD;
        if(mp.find(t) != mp.end()) dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
    cout << dp[n];
    return 0;
}