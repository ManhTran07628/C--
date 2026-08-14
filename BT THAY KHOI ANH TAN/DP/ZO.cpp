#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 2;i <= n;i++) {
        if(a[i]-a[i-1] > 0) {
            ans += a[i]-a[i-1];
        }
    }
    cout << ans;
    return 0;
}