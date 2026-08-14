#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 307;
int dp[MM][MM],n;
// dp[L][R] : so cach to mau trong doan tu L -> R toi uu nhat
vector<int> a;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> b;
    b.resize(n+7);
    for(int i = 1;i <= n;i++) cin >> b[i];
    a.push_back(0);
    for(int i = 1;i <= n;i++) {
        if(b[i] != b[i+1]) {
            a.push_back(b[i]);
        }
    }
    n = a.size()-1;
    for(int i = 1;i <= n;i++) {
        dp[i][i] = 1;
    }
    for(int len = 2;len <= n;len++) {
        for(int L = 1;L <= n-len+1;L++) {
            int R = L+len-1;
            dp[L][R] = dp[L+1][R] + 1;
            for(int k = L+1;k <= R;k++) {
                if(a[L] == a[k]) 
                    dp[L][R] = min(dp[L][R],dp[L+1][k-1] + dp[k][R]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}