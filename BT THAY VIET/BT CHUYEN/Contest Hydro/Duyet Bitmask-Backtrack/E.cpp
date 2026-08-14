#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[25];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 1e18;
    for(int mask = 0;mask < (1 << (n-1));mask++) {
        int segment = 0,d = 0;
        for(int i = 0;i < n-1;i++) {
            segment |= a[i+1];
            if((mask >> i) & 1) {
                d ^= segment;
                segment = 0;
            }
        }
        segment |= a[n];
        d ^= segment;
        ans = min(ans,d);
    }
    cout << ans;
    return 0;
}