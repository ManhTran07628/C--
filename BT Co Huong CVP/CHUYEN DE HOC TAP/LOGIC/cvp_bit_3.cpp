#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MOD = 1e9+7;
const int LOG = 60;
int t;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll res = 0;
        for(int i = LOG;i >= 0;i--) {
            for(int j = i-1;j >= 0;j--) {
                ll nums = (1ll << i) + (1ll << j);
                if(nums <= n) res += nums;
                res %= MOD;
            }
        }
        cout << res << '\n';
    }
    return 0;
}