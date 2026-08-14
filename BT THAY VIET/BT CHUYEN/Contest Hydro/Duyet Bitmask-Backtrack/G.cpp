#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int p[25];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> p[i];
    }
    int ans = 1e18;
    for(int mask = 1;mask < (1 << n);mask++) {
        int sum1 = 0,sum2 = 0;
        for(int i = 0;i < n;i++) {
            if((mask >> i) & 1) sum1 += p[i+1];
            else sum2 += p[i+1];
        }
        ans = min(ans,abs(sum1-sum2));
    }
    cout << ans;
    return 0;
}