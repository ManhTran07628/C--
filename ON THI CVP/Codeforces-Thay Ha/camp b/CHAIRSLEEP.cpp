#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<ll,ll> a[N];
multiset<ll> ms;
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
    ll n,h;
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
    }
    for(int i = 1;i <= n;i++) {
        cin >> a[i].se;
    }
    sort(a+1,a+n+1);
    ll sum = 0,i = 1,j = 1,ans = 1e9;
    while(i <= n && j <= n) {
        if(sum < h) {
            sum += a[j].se;
            ms.insert(a[j].fi - a[j-1].fi);
            j++;
        }
        while(sum >= h) {
            ans = min(ans,*ms.begin());
            ms.erase(a[i+1].fi - a[i].fi);
            sum -= a[i].fi;
            i++;
        }
    }
    cout << ans;
    return 0;
}