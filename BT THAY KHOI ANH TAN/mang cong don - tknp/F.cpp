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
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ll j = lower_bound(a+i,a+n+1,q+a[i-1])-a;
        if(a[j]-a[i-1] == q) ans++;
    }
    cout << ans;
    return 0;
}