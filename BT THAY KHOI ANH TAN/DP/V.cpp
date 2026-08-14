#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[55],n,x,q;
void solve() {
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    double ans = x;
    for(int i = 2;i <= n;i++) {
        if(a[i] > a[i-1]) {
            double p = a[i-1];
            double temp = ans * (a[i]/p) - (ans*0.01)*2;
            if(ans < temp) 
                ans = temp;
        }
    }
    cout << fixed << setprecision(5) << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}