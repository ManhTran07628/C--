#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
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
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll ans = N;
    for(int i = 1;i <= n;i++) {
        ll pos = lower_bound(b+i,b+n+1,m+b[i-1]) - b;
        if(pos != n+1) ans = min(ans,pos-i+1);
    }
     if(ans == N) cout << -1;
     else cout << ans;
    return 0;
}