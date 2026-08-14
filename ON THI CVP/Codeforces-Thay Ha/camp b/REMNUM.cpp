#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
unordered_map<ll,ll> x,y;
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
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
        x[a[i]]++;
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        y[b[i]]++;
    }
    ll ans = 0;
    for(pair<ll,ll> f:x) {
        ans += min(f.se,y[f.fi]);
    }
    cout << ans;
    return 0;
}