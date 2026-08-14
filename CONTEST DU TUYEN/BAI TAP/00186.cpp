#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5;
ll n,T;
pii t[MM + 5];

priority_queue<int> q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    for(int i = 1;i <= n;i++) cin >> t[i].fi >> t[i].se;
    int res = 0; ll cur_time = 0;
    for(int i = 1;i <= n;i++) {
        q.push(t[i].se);
        cur_time += t[i].se;
        while(!q.empty() && cur_time + t[i].fi > T) {
            cur_time -= q.top();
            q.pop();
        }
        res = max(res,(int) q.size());
    }
    cout << res;
    return 0;
}