#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
map<ll,ll> f;

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
    f[0] = 1;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = (a[i]%n+n)%n;
        b[i] = (b[i-1]+a[i])%n;
        ans += f[b[i]];
        f[b[i]]++;
    }
    cout << ans;
    return 0;
}