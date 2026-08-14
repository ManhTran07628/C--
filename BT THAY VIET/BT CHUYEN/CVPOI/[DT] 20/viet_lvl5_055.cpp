#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k;
ll w[MM];

namespace subtask1
{
    vector<ll> cur_sz;
    void solve()
    {
        int LG = __lg(n);
        int min_sz = oo;
        for(int i = LG;i >= 0;i--) {
            if(n >> i & 1) {
                // cout << i << ' ';
                min_sz = i + (i == 0);
                for(int j = 1;j <= (1 << i);j++) cur_sz.push_back(i + (i == 0));
            }
        }
        
        // for(auto e:cur_sz) cout << e << ' '; cout << '\n';

        sort(w + 1,w + n + 1);
        sort(cur_sz.begin(),cur_sz.end());
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            res += w[i] * cur_sz[i - 1];
            // cout << w[i] << ' ' << cur_sz[i - 1] << '\n';
        }
        cout << res << '\n' << min_sz;
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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> w[i];
    if(k == 2 && n <= 1000) subtask1::solve();
    return 0;
}