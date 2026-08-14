#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 31;
int n;
ll a[MM];
vector<ll> A,B;

void Try(int l,int r,int id,ll sum,vector<ll> &f,int cnt)
{
    if(id == r + 1) {
        if(cnt == 0) return;
        f.push_back(sum);
        return;
    }
    Try(l,r,id + 1,sum + a[id],f,cnt+1);
    Try(l,r,id + 1,sum,f,cnt);
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
    if(n == 1) {
        cout << abs(a[1]);
        return 0;
    }
    if(n == 2) {
        cout << abs(a[1] - a[2]);
        return 0;
    }
    Try(1, n/2, 1, 0, A, 0);
    Try(n/2+1, n, n/2+1, 0, B, 0);
    sort(B.begin(),B.end());
    ll res = oo;
    for(auto x:A) {
        auto y = lower_bound(B.begin(),B.end(),sum / 2 - x);
        ll fa = x + *y;
        ll fb = sum - fa;
        res = min(res,abs(fa - fb));
    }
    cout << res;
    return 0;
}
