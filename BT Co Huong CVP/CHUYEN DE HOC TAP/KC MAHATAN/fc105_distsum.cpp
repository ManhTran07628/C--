#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
ll n,a[MM],b[MM];
ll psx[MM],psy[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        psx[i] = psx[i-1] + a[i];
        psy[i] = psy[i-1] + b[i];
    }
    for(int i = 1;i <= n;i++) {
        ll right = psx[n] - psx[i] - a[i] * (n - i); 
        res += right;
    }
    for(int i = 1;i <= n;i++) {
        ll right = psy[n] - psy[i] - b[i] * (n - i); 
        res += right;
    }
    cout << res;

    return 0;
}