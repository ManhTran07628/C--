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
    int n;
    cin >> n;
    int ans = 0;
    for(int x = 1;x <= n;x++) {
        int p =(2*x*x*x+3*x*x+x)/6;
        if(p <= n) ans++;
        else break;
    }
    cout << ans;
    return 0;
}