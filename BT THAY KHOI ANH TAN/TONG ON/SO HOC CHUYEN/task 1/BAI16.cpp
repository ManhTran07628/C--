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
        int n;
        cin >> n;
        if(n % 2 == 1) n++;
        int ans = max(6LL,n)*2.5;
        cout << ans << '\n';
    }
    return 0;
}