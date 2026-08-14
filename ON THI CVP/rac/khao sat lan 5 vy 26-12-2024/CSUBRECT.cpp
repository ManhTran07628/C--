#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CSUBRECT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    ll l = 0,r = m,ans = 0;
    for(int i = 1;i <= n;i++) {
        ll a,b;
        cin >> a >> b;
        l = max(l,a);
        r = min(r,b);
        ans = max(ans,(r-l+1)*i);
    }
    cout << ans;
    return 0;
}