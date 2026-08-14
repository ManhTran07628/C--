#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
ll n,ps[MM];
pii a[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].fi;
    for(int i = 1;i <= n;i++) cin >> a[i].se;

    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++)
        ps[i] = ps[i-1] + a[i].se;
    
    ll weight = ps[n];
    ll L = 0,R = 0;
    for(int i = 1;i <= n;i++) {
        if(ps[i] * 2 >= weight) {
            L = a[i].fi;
            break;
        }
    }

    for(int i = n;i >= 1;i--) {
        if(ps[i-1] * 2 <= weight) {
            R = a[i].fi;
            break;
        }
    }
    cout << max(0ll,R - L + 1);
    return 0;
}
