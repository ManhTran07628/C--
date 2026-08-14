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
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if(a < k) ans += k-a;
    if(b < k) ans += k-b;
    if(c < k) ans += k-c;
    cout << ans;
    return 0;
}