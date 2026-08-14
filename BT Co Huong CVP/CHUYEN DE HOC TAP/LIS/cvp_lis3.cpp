#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll a[MM],dpL[MM],dpR[MM];
int n;
namespace subtask1
{
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            dpL[i] = 1;
            for(int j = 1;j < i;j++)
                if(a[i] > a[j])
                    dpL[i] = max(dpL[i],dpL[j] + 1);
        }

        for(int i = n;i >= 1;i--) {
            dpR[i] = 1;
            for(int j = n;j > i;j--)
                if(a[i] > a[j])
                    dpR[i] = max(dpR[i],dpR[j] + 1);
        }

        ll res = 0;
        for(int i = 1;i < n;i++) {
            ll cur = dpL[i] + dpR[i+1];
            if(a[i] == a[i+1]) cur--;
            res = max(res,cur);
            // cout << dpL[i] << ' ' << dpR[i+1] << '\n';
        }
        cout << res;
    }
}

namespace subtask2
{
    void solve()
    {
         ll res = 1;
    
        for(int i = 1;i <= n;i++) {
            dpL[i] = 1;
            for(int j = 1;j < i;j++)
                if(a[i] > a[j])
                    dpL[i] = max(dpL[i],dpL[j] + 1);
        }

        for(int i = n;i >= 1;i--) {
            dpR[i] = 1;
            for(int j = n;j > i;j--)
                if(a[i] > a[j])
                    dpR[i] = max(dpR[i],dpR[j] + 1);
        }

        for(int i = 1;i < n;i++) {
            if(dpL[i] > 1 && dpR[i] > 1) { 
                res = max(res, dpL[i] + dpR[i] - 1);
            }
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= 200) subtask1::solve();
    else subtask2::solve();
    return 0;
}