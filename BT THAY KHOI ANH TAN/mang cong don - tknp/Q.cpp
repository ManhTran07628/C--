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
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    while(q--) {
        int u,v;
        cin >> u >> v;
        int x = lower_bound(a+u,a+v+1,(a[v]-a[u-1])/2)-a;
        int d1 = (a[v]-a[u-1])-(a[x]-a[u-1]);
        int d2 = (a[v]-a[u-1])-(a[x-1]-a[u-1]);
        if(d1 >= d2) cout << d2;
        else cout << d1;
        cout << '\n';
    }
    return 0;
}   