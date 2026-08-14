#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int x[105],dp[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s = 0,cnt = 0;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
        s += x[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = s;j >= x[i];j--) {
            if(dp[j-x[i]]) dp[j] = 1;
        }
    }
    for(int i = 1;i <= s;i++)  if(dp[i]) cnt++;
    cout << cnt << '\n';
    for(int i = 1;i <= s;i++)  if(dp[i]) cout << i << ' ';
    return 0;
}