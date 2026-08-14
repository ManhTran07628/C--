#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],pre_min[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1,greater<int>());
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            ans = max(ans,a[i]*i);
        }
        cout << ans << '\n';
    }
    return 0;
}   