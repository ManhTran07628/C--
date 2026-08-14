#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "chonoi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = 0;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        ll fi = upper_bound(a+1,a+n+1,k-a[i]) - a;
        if(fi > i) {
            ans += fi - i - 1;
        }
    }
    // ll ans = fi*(fi-1)/2;
    cout << ans;
    return 0;
}