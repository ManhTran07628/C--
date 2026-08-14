#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll tong = 0,a[N];
ll n,v,max1 = -1e9;
void quaylui(ll i,ll k)
{
    if(tong <= v) {
        max1 = max(max1,tong);
    }
    for(;i <= n;i++) {
        if(tong + a[i] <= v) {
            tong += a[i];
            quaylui(i+1,tong);
            tong -= a[i];
        }
    }
}


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
    cin >> n >> v;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        if(a[i] > v) {
            n = i;
            break;
        }
    }
    quaylui(1,tong);
    cout << max1;
    return 0;
}