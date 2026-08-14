#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll n,m,sum = 0;
ll solve(ll k)
{
    ll ans = 0;
    for(int i = 1;i <= m;i++) {
        ans += (a[i]+k-1)/k;
        if(ans > n) return 0;
    }
    return 1;
}

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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll l = 1,r = sum,ans = n;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(solve(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}