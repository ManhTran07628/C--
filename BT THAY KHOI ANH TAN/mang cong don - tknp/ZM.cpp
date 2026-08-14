#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1,a+n+1);
    int ans = n-1;
    for(int i = 1;i <= n;i++) {
        int p = sum / a[i];
        if(p > i) p = i;
        ans = min(ans,n-p);
    }
    cout << ans;
    return 0;
}