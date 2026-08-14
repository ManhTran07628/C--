#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],b[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x,y,n;
        cin >> x >> y >> n;
        int cnt = 0;
        while (n > 1) {
            if (x > y) {
                int step = min(n-1,x/y);
                x -= step * y;
                n -= step;
            } else {
                int step = min(n-1,y/x);
                y -= step * x;
                n -= step;
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}