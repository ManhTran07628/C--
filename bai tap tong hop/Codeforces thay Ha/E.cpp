#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int t,n,m,k;
pair<ll,ll> a[MM];

void solve()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i].second;
    for(int i = 1;i <= n;i++) cin >> a[i].first;
    sort(a+1,a+n+1,greater<pair<int,int>>());
    ll cost = 0,total = 0;
    for(int i = 1;i <= n;i++) {
        ll val = a[i].first, cur_cost = a[i].second;
        if(cost + cur_cost <= m) {
            cost += cur_cost;
            total += val;
        }
        else {
            if(k == 0) break;
            k--;
            ll min_cost = cur_cost,id = i+1;
            for(int j = i+1;j <= n;j++) {
                if(min_cost > a[j].second) {
                    min_cost = a[j].second;
                    id = j;
                }
            }
            if(cost + min_cost <= m) {
                swap(a[i].second,a[id].second);
                cost += min_cost;
                total += val;
            }
        }
    }
    cout << total << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}