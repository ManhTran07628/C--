#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 35;
int n;
ll a[MM];
vector<ll> A,B;

void Try(int l,int r,int id,ll sum,vector<ll> &f)
{
    if(id == r + 1) {
        f.push_back(sum);
        return;
    }
    Try(l,r,id + 1,sum + a[id],f);
    Try(l,r,id + 1,sum,f);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n; 
    ll sum = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    // if(n == 1) {
    //     cout << abs(a[1]) << ' ' << 1;
    //     return 0;
    // }
    // if(n == 2) {
    //     cout << abs(a[1] - a[2]) << ' ' << 1;
    //     return 0;
    // }
    Try(1, n/2, 1, 0, A);
    Try(n/2+1, n, n/2+1, 0, B);
    sort(B.begin(),B.end());
    ll res = oo, cnt = 0;
    for(auto x:A) {
        auto y = lower_bound(B.begin(),B.end(),sum / 2 - x);

        if(y != B.end()) {
            if(res > abs( sum - 2 * (x + *y) )) res = abs( sum - 2 * (x + *y) );
        }

        if(y != B.begin()) {
            --y;
            if(res > abs( sum - 2 * (x + *y) )) res = abs( sum - 2 * (x + *y) );
        }
    }
    for(auto x:A) {
        ll val = sum - 2 * x - res;
        
        auto range = equal_range(B.begin(),B.end(),val / 2);
        cnt += range.se - range.fi;
        
        if(res != 0) {
            val = sum - 2 * x + res;
            auto range = equal_range(B.begin(),B.end(),val / 2);
            cnt += range.se - range.fi;
        }
    }
    // if(res == 0) cout << res << ' ' << cnt / 2;
    cout << res << ' ' << cnt / 2;
    return 0;
}
