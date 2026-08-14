#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
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
    ll n,c;
    cin >> n >> c;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll pos1 = lower_bound(a+1,a+n+1,a[i]-c) - a;
        ll pos2 = upper_bound(a+1,a+n+1,a[i]-c) - a;
        ans += pos2 - pos1;
        cout << ans << " ";
    }
    cout << ans;
    return 0;
}