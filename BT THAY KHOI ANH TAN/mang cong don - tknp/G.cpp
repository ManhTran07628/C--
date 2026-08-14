#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,p,r;
    cin >> n >> p >> q >> r;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int x = 1;x <= n;x++) {
        ll y = lower_bound(a+x,a+n+1,p+a[x-1])-a;
        ll z = lower_bound(a+y+1,a+n+1,q+a[y])-a;
        ll w = lower_bound(a+z+1,a+n+1,r+a[z])-a;
        if(a[y]-a[x-1]==p && a[z]-a[y]==q && a[w]-a[z]==r) ans++;
    }
    cout << ans;
    return 0;
}