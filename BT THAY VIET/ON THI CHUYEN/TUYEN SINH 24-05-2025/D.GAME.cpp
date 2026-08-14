#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int n,def = 0,m;

int cost(int x,int y) {
    int res = LLONG_MAX;
    int pos = lower_bound(a+1,a+n+1,x)-a;
    if(pos <= n) {
        int c = 0;
        if(def-a[pos] < y)
            c = y-(def-a[pos]);
        res = min(res,c);
    }
    pos = upper_bound(a+1,a+n+1,x)-a-1;
    if(pos >= 1) {
        int c = x - a[pos];
        if(def-a[pos] < y)
            c += y-(def-a[pos]);
        res = min(res,c);
    }
    return res;
}

void solve()
{
    int x,y;
    cin >> x >> y;
    cout << cost(x,y) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        def += a[i];
    }
    sort(a+1,a+n+1);
    cin >> m;
    while(m--) {
        solve();
    }
    return 0;
}