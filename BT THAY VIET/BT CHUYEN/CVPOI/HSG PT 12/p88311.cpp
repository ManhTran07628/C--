#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e5 + 7;
int n, k;
int a[MM],dif[MM];
namespace subtask1
{
    int dp[MM];
    void solve()
    {
        dp[1] = 1;
        for(int i = 1;i <= n;i++) {
            if(!dp[i]) continue;
            for(int j = i + 1;j <= n;j++) {
                if(abs(a[i] - a[j]) <= k) dp[j] = 1;
            }
        }
        int res = 0;
        for(int i = 1;i <= n;i++) cout << dp[i] << ' ';
    }
}

namespace subtask2
{
    int ans[MM];
    void solve()
    {
        for(int i = 1;i <= n;) {
            int j = upper_bound(a+1,a+n+1,a[i] + k) - a - 1;
            if(i == j) break;
            for(int k = i;k <= j;k++) ans[k] = 1; 
            i = j;
        }
        for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    }
}

namespace subtask3
{
    void solve()
    {
        ll L = a[1] - k, R = a[1] + k;
        for(int i = 1;i <= n;i++) {
            if(L <= a[i] && a[i] <= R) {
                cout << 1 << ' ';
                L = min(L,(ll) a[i] - k);
                R = max(R,(ll) a[i] + k);
            }
            else cout << 0 << ' ';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= (int) 1e3) subtask1::solve();
    else subtask3::solve();
    return 0;
}