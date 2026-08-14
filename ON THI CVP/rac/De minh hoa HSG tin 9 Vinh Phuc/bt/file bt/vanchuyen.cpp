#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N= 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "vanchuyen"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    ll ans = -1;
    if(k >= n || k >= m) {
        cout << -1;
        return 0;
    }
    for(int i = 0;i <= min(n,k);i++) {
        ll cmp = a[i+1]+ta;
        ll j = lower_bound(b+1,b+m+1,cmp) - b;
        j += k - i;
        if (j > m) {
            cout << -1;
            return 0;
        }
        ans = max(ans,b[j]+tb);
    }
    cout << ans;
    return 0;
}