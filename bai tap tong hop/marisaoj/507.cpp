#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n;
ll a[MM],b[MM],c[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    ll res = oo;
    for(int i = 1,j = 1,k = 1;i <= n && j <= n && k <= n;) {
        // cout << i << ' ' << j << ' ' << k << ' ' << a[i] << ' ' << b[j] << ' ' << c[k] << '\n';
        res = min(res,abs(a[i] - b[j]) + abs(b[j] - c[k]) + abs(c[k] - a[i]));
        if(a[i] <= b[j] && a[i] <= c[k]) i++;
        else if(b[j] <= a[i] && b[j] <= c[k]) j++;
        else if(c[k] <= a[i] && c[k] <= b[j]) k++;
    }
    cout << res;
    return 0;
}