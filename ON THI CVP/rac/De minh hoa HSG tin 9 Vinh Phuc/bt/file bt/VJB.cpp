#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll tong = 0,sls1 = 0,sls2 = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            tong += a[i];
            if(a[i] == 1) sls1++;
            else sls2++;
        }
        if(sls2 % 2 != 0 && sls1 == 0) {
            cout << "NO" << '\n';
            continue;
        }
        if(sls1 % 2 != 0 && sls2 == 0) {
            cout << "NO" << '\n';
            continue;
        }
        if(tong % 2 == 0) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}