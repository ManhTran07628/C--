#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,a[MM],ps[MM];


ll getsum(ll l,ll r)
{
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}

namespace subtask12
{
    void solve()
    {
        int res = 0;
        for(int i = 1;i <= n;i++) {
            int maxval = a[i], minval = a[i];
            for(int j = i;j <= n;j++) {
                maxval = max(maxval,a[j]);
                minval = min(minval,a[j]);

                ll sum = ps[j] - ps[i - 1];

                if(getsum(minval,maxval) == sum) res++;
            }
        }

        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    subtask12::solve();
    return 0;
}