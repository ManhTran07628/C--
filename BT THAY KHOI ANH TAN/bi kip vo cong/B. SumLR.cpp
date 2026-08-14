#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
multiset<int> ms;
int a[MAXN],ps[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    int ans = -1e18;
    for(int i = l;i <= n;i++) {
        ms.insert(ps[i-l]);
        int min_val = *ms.begin();
        ans = max(ans,ps[i]-min_val);
        if(i-r >= 0) ms.erase(ms.find(ps[i-r]));
    }
    cout << ans;
    return 0;
}