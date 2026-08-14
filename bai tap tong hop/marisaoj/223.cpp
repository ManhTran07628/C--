#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 25;
int n,a[MM];
ll L,R;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> R; ll res = 0;
    for(int i = 0;i < n;i++) cin >> a[i];

    for(int mask = 1;mask < (1 << n);mask++) {
        ll mul = 1, ok = 1;
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                if(mul > R / a[i]) {
                    ok = 0;
                    break;
                }
                else mul *= a[i];
            }
            
        }
        if(!ok) continue;
        // cout << mul << '\n';

        int sz = __builtin_popcount(mask);
        if(sz % 2) res += sz * (R / mul - (L - 1) / mul);
        else res -= sz * (R / mul - (L - 1) / mul);
    }
    cout << res;
    return 0;
}