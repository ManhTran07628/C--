#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n;
ll ps[MM],val[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a; cin >> a;
        ll cnt = 1;
        while(a % 2 == 0) {
            cnt *= 2;
            a /= 2;
        }
        ps[i] = ps[i-1] + cnt;
        val[i] = a;
        // cout << val[i] << ' ' << ps[i] << '\n';
    }
    int q; cin >> q;
    for(int i = 1;i <= q;i++) {
        ll a; cin >> a;
        int pos = lower_bound(ps+1,ps+n+1,a) - ps;
        cout << val[pos] << '\n';
    }
    return 0;
}