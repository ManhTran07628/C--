#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,m,p[MM];

void ReadInput()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> p[i];
}

namespace subtask1
{
    void solve()
    {
        sort(p+1,p+n+1);
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            ll cnt = 0;
            for(int j = i+1;j <= n;j++) {
                if(p[i] + p[j] <= m) cnt++;
            }
            ans += cnt*2;
        }
        cout << ans;
    }
}

namespace subtask2
{
    void solve()
    {
        sort(p+1,p+n+1);
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            int pos = upper_bound(p+i,p+n+1,m-p[i])-p;
            ll cnt = pos-i-1;
            if(cnt > 0) ans += cnt*2;
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ReadInput();
    if(n <= 1000) subtask1::solve();
    else subtask2::solve();
    return 0;
}