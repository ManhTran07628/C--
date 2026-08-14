#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
ll n,W,k,w[MM],v[MM];
ll dp[101][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> W >> k;
    if(k > n) {
        cout << -1;
        return 0;
    }
    vector<ll> s;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
        s.push_back(w[i]);
    }
    sort(s.begin(),s.end());
    ll sum = 0;
    for(int i = 0;i < k;i++) sum += s[i];
    if(sum > W) {
        cout << -1;
        return 0;
    }

    for(ll i = 1;i <= n;i++) {
        for(int d = W;d >= w[i];d--) 
            for(int j = 1;j <= min(i,k);j++) 
                dp[j][d] = max(dp[j][d],dp[j - 1][d - w[i]] + v[i]);
            
    }

    cout << dp[k][W];
    return 0;
}
