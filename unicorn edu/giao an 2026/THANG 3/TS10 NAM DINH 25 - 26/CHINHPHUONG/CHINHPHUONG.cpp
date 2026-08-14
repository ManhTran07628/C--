#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;

ll dp[11][90005];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "CHINHPHUONG"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k; cin >> n >> k;
    int targetSum = (k - 1) * n;
    
    vector<int> squares;
    for (int i = 0; i * i <= n; ++i) {
        squares.push_back(i * i);
    }

    dp[0][0] = 1;

    for (int v : squares) {
        for (int j = k; j >= 1; --j) {
            for (int s = targetSum; s >= v; --s) {
                if (dp[j - 1][s - v] > 0) {
                    dp[j][s] += dp[j - 1][s - v];
                }
            }
        }
    }

    cout << dp[k][targetSum];
    return 0;
}