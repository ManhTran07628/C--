#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
map<ll,pair<ll,ll>> b;

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
        cin >> a[i];
        b[a[i]].fi++;
        b[a[i]].se = i;
    }
    for(int i = 1;i <= n;i++) {
        if(b[k-a[i]].fi > 0 && k - a[i] != a[i]) {
            cout << b[a[i]].se << " " << b[k-a[i]].se;
            return 0;
        }
        if(b[k-a[i]].fi >= 2 && k-a[i] == a[i]) {
            ll p1 = 0,p2 = 0;
            for(int j = 1;j <= n;j++) {
                if(a[j] == a[i] && p1 == 0) {
                    p1 = j;
                    continue;
                }
                if(a[j] == a[i] && p1 != 0 && p2 == 0) {
                    p2 = j;
                    break;
                }
            }
            cout << p1 << " " << p2;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}