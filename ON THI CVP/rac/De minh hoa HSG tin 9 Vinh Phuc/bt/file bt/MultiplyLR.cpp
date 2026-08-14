#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MultiplyLR"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        ll tong1 = 0,tong = 0;
        for(int i = 1;i <= n/2;i++) {
            tong += a[i];
        }
        for(int i = n/2+1;i <= n;i++) {
            tong1 += a[i];
        }
        cout << tong * tong1 << '\n';
    }
    return 0;
}