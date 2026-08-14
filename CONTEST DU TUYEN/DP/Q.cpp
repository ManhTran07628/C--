#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3000 + 7;
const int MOD = 1e9 + 7;
int n;
ll dp[MM][MM][2];
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    s = ' ' + s;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1;i < n;i++) {
        if(s[i] == '<') {
            cnt1++;
            for(int j = i+1;j < n;j++) {
                dp[j][cnt1][]
            }
        }
    }
    ll res = 0;
    for(int i = 1;i <= n;i++)
        res = (res + dp[n][i]) % MOD;
    cout << res;
    return 0;
}