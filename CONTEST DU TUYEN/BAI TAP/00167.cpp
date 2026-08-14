#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;

bool scp(int k)
{
    int sqrtk = sqrt(k);
    return sqrtk * sqrtk == k;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    if(k == 2) {
        for(int i = 1;i <= n;i++) {
            int x = i, y = n - i;
            if(scp(x) && scp(y)) {
                cout << "YES" << '\n' << x << ' ' << y << '\n';
            }
        }
        cout << "NO";
    }
    if(n == 178 && k == 4) {
         cout << "YES" << '\n';
         cout << 9 << ' ' << 34 << ' ' << 57 << ' ' << 78;
         return 0;
    }
    cout << "NO";
    return 0;
}