#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 35000 + 7;
ll t,n,q;
ll x[MM],a[MM];

bool check(double len,ll r,ll maxline)
{
    ll cnt;
    double cur_pos = 0;

    if(r == 0) {
        cur_pos = x[1] + len;
        cnt = 1;
    }
    else {
        cur_pos = a[1];
        cnt = 0;
    }

    for(int i = 1, j = 1; j <= n; j++) {

        // chuyển sang trạm có sẵn nếu trạm hiện tại không phủ được
        while(i <= r && x[j] > a[i] + len) i++;

        if(i <= r && fabs(x[j] - a[i]) <= len) {
            cur_pos = a[i];
            continue;
        }

        if(fabs(cur_pos - x[j]) <= len) continue;

        // đặt trạm mới
        cur_pos = x[j] + len;
        cnt++;

        if(cnt > maxline) return false;
    }

    return true;
}

void solve(int k,int r)
{
    double L = 0, R = 1e9;
    for(int i = 1;i <= 300;i++) {
        double mid = L + (R - L) / 2;
        if(check(mid,r,k - r)) R = mid;
        else L = mid;
    }
    cout << R << ' ';
}

void Queries()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int t = 1;t <= q;t++) {
        ll k,r; cin >> k >> r;
        for(int i = 1;i <= r;i++) cin >> a[i];

        sort(x+1,x+n+1);
        sort(a+1,a+r+1);

        solve(k,r);
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        Queries();
        cout << '\n';
    }
    return 0;
}