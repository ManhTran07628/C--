#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
ll a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,u,v; cin >> n >> u >> v;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    deque<ll> dq;
    ll res = -oo;
    dq.push_back(0);
    for(int i = u;i <= n;i++) {
        while(!dq.empty() && i - v > dq.front()) dq.pop_front();
        while(!dq.empty() && a[dq.back()] >= a[i - u]) dq.pop_back();
        dq.push_back(i - u);
        if(!dq.empty()) res = max(res,a[i] - a[dq.front()]);
    }
    cout << res;
    return 0;
}