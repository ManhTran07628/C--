#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m;
ll a[MM],b[MM];

bool check(ll x)
{
    ll T_free = 0, T_need = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i] >= b[i] && x <= m * a[i]) {
            ll listen = (x + a[i] - 1) / a[i];
            T_free += m - listen;
        }
        else if(a[i] >= b[i] && x > m * a[i]) {
            ll listen = m;
            T_free += m - listen;
            T_need += (x - m * a[i] + b[i] - 1) / b[i];
        }
        else if(a[i] < b[i]) {
            T_free += m;
            T_need += (x + b[i] - 1) / b[i];
        }
    }
    return T_need <= T_free;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    ll L = 0,R = 1e18,ans = 0;
    // cout << check(19);
    while(L <= R) {
        ll mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << ans;
    return 0;
}
