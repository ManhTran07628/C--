#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],dem[N],f[N];
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
    ll tong = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dem[a[i]] += a[i];
    }

    f[1] = dem[1];
    f[2] = max(dem[1],dem[2]);
    ll max1 = -1e9;
    for(int i = 3;i <= 100000;i++) {
        f[i] = max(f[i-2]+dem[i],f[i-1]);
        max1 = max(max1,f[i]);
    }
    cout << max1;
    return 0;
}