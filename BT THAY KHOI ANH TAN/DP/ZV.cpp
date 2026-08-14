#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int s = 0;
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ok = 0;
    for(int i = 1;i <= n;i++) {
        s = (s + a[i]) % m;
        dp[s%m]++;
        dp[a[i]%m]++; 
        if(dp[m-s%m] > 0) ok = 1;
        if(dp[m-a[i]%m] > 0) ok = 1;
    }
    cout << (ok ? "YES" : "NO");
    return 0;
}