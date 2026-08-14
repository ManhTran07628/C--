#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

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
    ll n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll vtd = lower_bound(b+1,b+n+1,x-a[i]) - b;
        ll vtc = upper_bound(b+1,b+n+1,x-a[i]) - b;
        ans += vtc - vtd;
    }
    cout << ans;
    return 0;
}