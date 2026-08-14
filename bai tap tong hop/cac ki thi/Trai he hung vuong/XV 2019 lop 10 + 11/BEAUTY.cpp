#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e5 + 7;
ll n,a[MM];


namespace sol
{
    ll premin[MM][2] = {};
    ll ps[MM];
    // 0 -> even   1 -> odd
    void solve()
    {
        ll res = -oo;

        premin[0][1] = oo;

        for(int i = 1;i <= n;i++) {
            ps[i] = ps[i - 1] + a[i];
            if(i % 2 == 0) {
                premin[i][0] = min(premin[i - 1][0],ps[i]);
                premin[i][1] = premin[i - 1][1];
            }
            else {
                premin[i][1] = min(premin[i - 1][1],ps[i]);
                premin[i][0] = premin[i - 1][0];
            }
        }

        for(int i = 4;i <= n;i++) {
            res = max(res,ps[i] - premin[i - 4][i % 2]);
        }
        cout << res;
    }
}

namespace subtask1
{
    void solve()
    {
        ll res = -oo;
        for(int i = 1;i <= n;i++) {
            for(int j = i + 3;j <= n;j++) {

                if((j - i + 1) >= 4 && (j - i + 1) % 2 == 0) {
                    ll sum = 0;
                    for(int k = i;k <= j;k++) sum += a[k];
                    res = max(res,sum);
                }


            }
        }

        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BEAUTY"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sol::solve();
    return 0;
}