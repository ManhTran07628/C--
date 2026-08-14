#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N],b[N];

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
    ll m = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        l[i] = max(l[i-1],a[i]);
    }
    for(int i = n;i >= 1;i--) {
        r[i] = max(r[i+1],a[i]);
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        b[i] = min(l[i],r[i]) - a[i];
        ans += b[i];
    }
    cout << ans;
    return 0;
}