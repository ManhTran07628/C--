#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "evensum"
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
        ll dem = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++) {
            ll tong = 0;
            for(int j = i;j <= n;j++) {
                tong += a[j];
                if(tong % 2 == 0) dem++;
            }
        }
        cout << dem << '\n';
    }
    return 0;
}