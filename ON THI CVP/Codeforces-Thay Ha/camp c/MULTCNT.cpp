#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int L,R,a,b;
        cin >> L >> R >> a >> b;
        int d1 = R/a + R/b - R/lcm(a,b);
        int d2 = (L-1)/a + (L-1)/b - (L-1)/lcm(a,b);
        cout << d1-d2 << '\n';
    }
    return 0;
}