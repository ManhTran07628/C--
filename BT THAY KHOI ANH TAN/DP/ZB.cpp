#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN][3];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] == 1) {
            dp[i][1] = dp[i-1][1]; // truoc do deu la 1
            dp[i][2] = min(dp[i-1][1],dp[i-1][2])+1; // thay doi truoc do la 1 hoac la 2
        }
        else {
            dp[i][1] = dp[i-1][1]+1; // thay doi a[i] = 1
            dp[i][2] = min(dp[i-1][2],dp[i-1][1]); 
            // min cua truoc do la 1(hien tai la 2) hoac truoc do la 2
        }
    }
    cout << min(dp[n][1],dp[n][2]);
    return 0;
}