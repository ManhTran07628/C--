#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int p[MM],t[MM];
ll n,x;

ll cnt_egg(ll lim)
{
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        ll cur_time = lim;
        if(p[i] <= cur_time) {
            cnt++;
            cur_time -= p[i];
            cnt += cur_time / t[i]; 
        }
    }
    return cnt;
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
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> p[i] >> t[i];
    }

    ll L = 1, R = 1e18, res = 0;
    while(L <= R) {
        ll mid = (L + R) / 2;
        if(cnt_egg(mid) >= x) {
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << res;
    return 0;
}