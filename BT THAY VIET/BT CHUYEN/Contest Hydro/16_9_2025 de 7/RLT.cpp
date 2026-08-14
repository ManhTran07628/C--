#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,t,s,k,a[MM],q;

void readinput()
{
    cin >> n >> t >> s >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> q;
}

namespace subtask1
{
    ll b[MM];
    void solve()
    {
        while(q--) {
            ll h;
            cin >> h; 
            ll lim = a[n],cnt = 0,maxn = 1e7,r = 0;
            for(int i = 1;i <= n;i++) {
                b[i] = a[i];
                if(a[i] > h) cnt += a[i]-h;
                else if(a[i] <= h) r++;
            }
            ll costcb = 0;
            for(int i = 1;i <= n;i++) {
                if(a[i] > h && maxn > a[i]) {
                    maxn = a[i];
                }
            }
            for(int i = 1;i <= n;i++) {
                if(a[i] >= maxn) costcb += a[i]-maxn;
            }
            ll cost1 = cnt * t;
            ll cost2 = costcb * t + (s + k*r) * abs(h-maxn);
            cout << min(cost1,cost2) << ' ';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask1::solve();
    return 0;
}