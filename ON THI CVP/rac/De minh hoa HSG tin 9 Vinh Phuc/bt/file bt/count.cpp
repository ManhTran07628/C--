#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
unordered_map<ll,ll> b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "count"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 1 << " " << a[1];
        return 0;
    }
    sort(a+1,a+n+1);
    ll t = 0,c = 0;
    for(int i = 1;i <= n;i++) {
        ll vt = upper_bound(a+1,a+n+1,a[i]) - a;
        ll dem = 0,k1 = 0;
        for(int j = vt-1;j >= 1;j--) {
            if(k1 + a[i]-a[j] <= k) {
                dem++;
                k1 += a[i]-a[j];
            }
            else break;
        }
        if(dem > t) {
            c = a[i];
            t = dem;
        } 
        if(dem == t) c = min(c,a[i]);
    }
    cout << t << " " << c;
    return 0;
}