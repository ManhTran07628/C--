#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int x[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
        x[i] += x[i-1];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {// x[j]-x[i-1] <= k
        int j = upper_bound(x+i,x+n+1,k+x[i-1])-x;
        // cout << i << ' ' << j << '\n';
        ans += (j-i);
    }
    cout << ans;
    return 0;
}