#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BIENDOI"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,x,y; cin >> n >> x >> y;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] % 2 == 1) a[i] += x;
        else a[i] -= y;
    }

    for(int i = 1;i <= n;i++) cout << a[i] << ' '; cout << '\n';
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) cout << a[i] << ' '; cout << '\n';


    return 0;
}