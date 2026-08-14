#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N],c[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TRIANGLE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    ll ans = 0;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            ll k1 = upper_bound(c+1,c+n+1,abs(a[i]-b[j])) - c;
            ll k2 = lower_bound(c+1,c+n+1,a[i]+b[j]) - c;
            ans += k2 - k1;
        }
    }
    cout << ans;
    return 0;
}