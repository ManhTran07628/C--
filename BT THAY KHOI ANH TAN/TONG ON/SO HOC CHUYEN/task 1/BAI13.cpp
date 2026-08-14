#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        int ans = min({a,b,(a+b)/3});
        cout << ans << '\n';
    }
    return 0;
}