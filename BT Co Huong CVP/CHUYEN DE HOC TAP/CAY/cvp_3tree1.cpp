#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n == 0) cout << "EMPTY";
    else {
        ll sum = 0;
        for(int i = 1;i <= n;i++) sum += a[i];
        cout << *max_element(a+1,a+n+1) << '\n' << *min_element(a+1,a+n+1) << '\n' << sum;
    }
    return 0;
}