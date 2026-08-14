#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5;
ll n,C,h[MM + 5],cost[MM + 5];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> C;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 2;i <= n;i++) {
        cost[i] = (h[i] - h[i-1]) * (h[i] - h[i-1]) + C;
    }
    ll res = 0;
    for(int i = 1;i <= n;) {
        cout << i << ' ';
        ll try1 = 0, nxt = i+1, add = 0;
        for(int j = i + 1;j <= n;j++) {
            ll x = (h[i] - h[j]);
            ll try2 = x * x + C;
            try1 += cost[j];
            if(try2 <= try1) {
                add = try2;
                nxt = j;
                continue;
            }
            else break;
        }
        res += add;
        i = nxt;
    }
    cout << res;
    return 0;
}