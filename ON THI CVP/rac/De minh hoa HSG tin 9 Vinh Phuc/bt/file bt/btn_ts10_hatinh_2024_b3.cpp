#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll chan = 0,le = 0,tong = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tong += a[i];
        if(a[i] % 2 == 0) chan++;
        else le++;        // 3 chan 2 le
    }
    ll ans = 0;
    if(le % 2 != 0) {
        ll tmp = min(chan,le);
        ans = (tmp-1) * tmp / 2;
    }
    else {
        ll c1 = le;
        ans += (c1-1)*c1/2;
        ll c2 = chan;
        ans += (c2-1)*c2/2;
    }
    cout << ans;
    return 0;
}
// 1 7 10 18 22 23
// 3 3
