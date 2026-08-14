#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
ll a,b;


namespace subtask2
{
    void solve()
    {
        ll ans = 0;
        for(int i = a;i <= b;i++) {
            ll d = sqrt(i);
            ans += d;
        }
        cout << ans;
    }
}

namespace subtask3
{
    void solve()
    {
        ll ans = 0,fpos = -1;

        for(ll i = 1;i * i <= b;i++) 
            if(i * i > a) {
                fpos = i;
                break;
            }

        ll p = sqrt(a);
        ans += (fpos*fpos - a) * p;

        for(ll i = fpos;i * i <= b;i++) {

            ll nextpos = min((i+1) * (i+1),b + 1);

            ans += (nextpos - i*i) * i;

        }
        
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if(b <= 1000000) subtask2::solve();
    else subtask3::solve();
    return 0;
}