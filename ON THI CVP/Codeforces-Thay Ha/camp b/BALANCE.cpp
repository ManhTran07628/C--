#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
map<ll,ll> b;
pair<ll,ll> a[N];
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
    for(int i = 1;i <= n;i++) {
        cin >> a[i].se >> a[i].fi;
    }
    sort(a+1,a+n+1);
    b[0] = 0;
    ll v = 0,ans = 0;
    for(int i = 1;i <= n;i++) {
        v += (a[i].se == 0 ? 1: -1);
        if(b.find(v) != b.end()) ans = max(ans,a[i].fi - a[b[v]+1].fi);
        else b[v] = i;
    }
    cout << ans;
    return 0;
}