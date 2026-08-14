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
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int j = lower_bound(a+i+1,a+n+1,2*a[i])-a;
        int p1 = a[i];
        int p2 = a[j]-a[i];
        int p3 = a[n]-a[j];
        if(p1 <= p2 && p2 <= p3) ans = p1;
    }
    cout << ans;
    return 0;
}


// a[i] <= a[j]-a[i] <= a[n]-a[j];