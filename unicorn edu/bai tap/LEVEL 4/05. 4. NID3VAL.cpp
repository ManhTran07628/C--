#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e4 + 7;
int n,a[MM],dp[MM][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];


    // 0 - > tang   1  - > giam
    for(int i = 2;i <= n;i++) {
        if(a[i] == 1) {
            dp[i][0] = dp[]
        }
    }
    return 0;
}