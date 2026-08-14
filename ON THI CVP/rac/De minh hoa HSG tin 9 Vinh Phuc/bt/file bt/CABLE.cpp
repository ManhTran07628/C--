#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
ll f[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CABLE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i < n;i++) {
        cin >> a[i];
    }  
    f[1] = a[1];
    f[2] = a[1]+a[2];
    for(int i = 3;i < n;i++) {
        f[i] = min(f[i-1]+a[i],f[i-2]+a[i]);
    }
    cout << f[n-1];
    return 0;
}