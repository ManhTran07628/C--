#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],f[N];

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
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    f[1] = a[1];
    f[2] = f[1]+a[2];
    f[3] = max({f[2],f[0]+a[3]+a[2],f[1]+a[3]});
    for(int i = 4;i <= n;i++) {
        f[i] = max({f[i-1],f[i-3]+a[i]+a[i-1],f[i-2]+a[i]}); // 12 - 23 - 13
    }
    cout << f[n];
    return 0;
}