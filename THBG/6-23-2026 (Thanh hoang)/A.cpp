#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll n,s,w[MM],v[MM];
ll dp[250001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> s;
    ll val = 500 * 500;
    for(int i = 1;i <= n;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) cin >> v[i];
    // s = min(s,val);

    int id = 1;
    for(int i = 2;i <= n;i++) {
        if(v[i] * w[id] > v[id] * w[i]) {
            id = i;
        }
    }

    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = w[i];j <= val;j++) {
            dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
        }
    }

    if(s <= val) {
        cout << dp[s];
    }
    else {
        ll res = 0;
        for(int i = 0;i <= min(s,val);i++) {
            res = max(res,dp[i] + (s - i) / w[id] * v[id]);
        }
        cout << res;
    }

    return 0;
}