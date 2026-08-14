#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN];
int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(j-a[i] >= 0) dp[j] = (dp[j]+dp[j-a[i]]) % M;
        }
    }
    cout << dp[k];
    return 0;
}