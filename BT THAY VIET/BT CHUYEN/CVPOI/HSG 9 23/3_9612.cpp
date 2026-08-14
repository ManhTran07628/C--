#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int t,n;
ll a[MM];

namespace subtask1
{
    ll ps[MM];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            ps[i] = ps[i-1] + a[i];
        }


        ll res = ps[n];
        for(ll L = 1;L <= n;L++) 
            for(ll R = L;R <= n;R++) {
                ll sum = ps[L-1] + (ps[n] - ps[R]);
                sum += (R - L + 1) * (L + R);
                res = max(res,sum);
            }
        cout << res << '\n';


    }
}

namespace subtask2
{
    ll ps[MM];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            ps[i] = ps[i-1] + a[i];
        }


        ll res = ps[n];
        for(ll i = 1,j = 1;i <= n;i++) {
            while(j <= n && (j - i + 1) * (j + i) >= ps[j] - ps[i-1]) {
                res = max(res, ps[i-1] + ps[n] - ps[j] + (j - i + 1) * (j + i));
                j++;
            }
        }
        cout << res << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        subtask2::solve();
    }
    return 0;
}