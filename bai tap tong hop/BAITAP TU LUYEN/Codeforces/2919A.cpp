#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
pii a[MM],b[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i].fi;
            b[i].fi = a[i].fi;
        }
        a[1].se = 0;
        b[1].se = 1;
        for(int i = 2;i <= n;i++) {
            a[i].se = a[i-1].se ^ 1;
            b[i].se = b[i-1].se ^ 1;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        bool ok1 = 1,ok2 = 1;
        for(int i = 1;i < n;i++) {
            if(a[i].se == a[i+1].se) {
                ok1 = 0;
                break;
            }
        }
        for(int i = 1;i < n;i++) {
            if(b[i].se == b[i+1].se) {
                ok2 = 0;
                break;
            }
        }
        if(ok1 || ok2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}