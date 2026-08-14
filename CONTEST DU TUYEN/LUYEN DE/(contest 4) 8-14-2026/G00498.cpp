#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
int n;
pii events[MM];

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
        cin >> events[i].fi >> events[i].se;
    }
    sort(events+1,events+n+1,[] (pii a,pii b){return a.se < b.se;});
    ll cur_time = 0;
    priority_queue<ll> q;
    for(int i = 1;i <= n;i++) {
        cur_time += events[i].fi;
        q.push(events[i].fi);
        while(!q.empty() && cur_time > events[i].se) {
            cur_time -= q.top(); q.pop();
        }
    }
    cout << q.size();
    return 0;
}