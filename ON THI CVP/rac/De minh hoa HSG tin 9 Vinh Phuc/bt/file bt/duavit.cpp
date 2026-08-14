#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
pair<ll,ll> f[N];

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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        f[i].first = f[i-1].first + a1;
        f[i].second = i;
    }
    for(int i = 1;i <= k;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= k;i++) {
        ll vtd = lower_bound(f+1,f+n+1,a[i]) - f;
        cout << vtd-1 << '\n';
    }
    return 0;
}