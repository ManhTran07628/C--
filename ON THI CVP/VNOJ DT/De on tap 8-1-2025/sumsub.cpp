#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sumsub"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    fill(l,l+n+1,-1e18);
    fill(r,r+n+1,-1e18);
    ll sum = 0,max1 = -1e18;
    for(int i = 1;i <= n;i++) {
        sum += a[i];
        max1 = max(max1,sum);
        l[i] = max(max1,l[i-1]);
        if(sum < 0) sum = 0;
    }
    sum = 0,max1 = -1e18;
    for(int i = n;i >= 1;i--) {
        sum += a[i];
        max1 = max(max1,sum);
        r[i] = max(max1,r[i+1]);
        if(sum < 0) sum = 0;
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,l[i]+r[i+1]);
    }
    cout << ans;
    return 0;
}