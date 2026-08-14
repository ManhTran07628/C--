#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dpl[MAXN],dpr[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == 1) dpl[i] = dpl[i-1]+1;
    }
    for(int i = n;i >= 1;i--) {
        if(a[i] == 1) dpr[i] = dpr[i+1]+1;
    }
    int ans = 0;
    for(int i = 1;i <= n+1;i++) {
        if(a[i] == 1) ans = max(ans,dpl[i]);
        else ans = max(ans,dpl[i-1]+dpr[i+1]);
    }
    if(dpl[n] == n) ans--;
    cout << ans;
    return 0;
}