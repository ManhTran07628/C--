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
        ll kt = 0;
        if(n < 2020) {
            cout << "NO" << '\n';
            continue;
        }
        for(int i = 0;i*2020 <= n;i++) {
            for(int j = 0;i*2020+j*2021 <= n;j++) {
                if(i*2020+j*2021 == n) {
                    kt = 1;
                    break;
                }
            }
            if(kt == 1) break;
        }
        if(kt) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}