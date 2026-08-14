#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    if(n % m != 0) {
        cout << -1;
        return 0;
    }
    int k = n/m,ans = 1e9;
    for(int x = 1;x <= sqrt(k);x++) {
        if(k % x == 0) {
            int y = k/x;
            if( __gcd(x,y) == 1)
                ans = min(ans,x+y);
        }
    }
    cout << m*ans;
    return 0;
}
