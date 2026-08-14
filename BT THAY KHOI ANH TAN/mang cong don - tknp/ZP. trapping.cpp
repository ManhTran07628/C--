#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN],n,l[MAXN],r[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        l[i] = max(l[i-1],a[i]);
    }
    for(int i = n;i >= 1;i--) {
        r[i] = max(r[i+1],a[i]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += max(0LL,min(l[i],r[i])-a[i]);
    }
    cout << ans;
    return 0;
}   