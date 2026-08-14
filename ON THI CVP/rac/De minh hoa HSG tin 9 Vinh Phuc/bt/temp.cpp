#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


void solve()
{
    int l1,b1,l2,b2,l3,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    int ok = 0;
    if(l1 == b1+b2+b3) ok = 1;
    else if(b1 == l1+l2+l3) ok = 1;
    else if(l1+l2 == l1+l3 && b2+b3 == b1) ok = 1;
    else if(b1+b2 == b1+b3 && l2+l3 == l1) ok = 1;
    cout << (ok ? "YES" : "NO") << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}