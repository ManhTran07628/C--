#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N],b[N];
ll n,m;

ll check(ll k)
{
    ll sum = 0;
    for(int i = 1;i <= n;i++) {
        if(k <= a[i]) {
            sum += b[i];
        }
        else {
            if(a[i]+b[i] >= k)
            sum += a[i]+b[i] - k;
        }
    }
    return sum >= m;
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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) 
        l[i] = max(l[i-1],a[i]);
    for(int i = n;i >= 1;i--) 
        r[i] = max(r[i+1],a[i]);
    for(int i = 1;i <= n;i++)
        b[i] = min(r[i],l[i]) - a[i];

    ll l = 0,r = 2e9,ans = -1;
    
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}