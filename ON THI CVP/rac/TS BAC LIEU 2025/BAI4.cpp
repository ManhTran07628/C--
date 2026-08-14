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
        if(a[i] < 0) a[i] = abs(a[i]);
    }
    int ans = a[1];
    for(int i = 2;i <= n;i++) {
        ans = __gcd(ans,a[i]);
    }
    cout << ans;
    return 0;
}
