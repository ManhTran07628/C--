#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<ll> f;

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
        ll x;
        cin >> x;
        x *= 2;
        ll kt = 0;
        for(int i = 1;i * i <= x;i++) {
            if(x % i == 0) {
                ll s = i,p = x / i;
                if((s+p-1)%2 != 0) continue;
                ll b = (s+p-1)/2;
                ll a = s - b;
                if(a > 0 && b > 0 && a != b) {
                    cout << a << ' ' << b << '\n';
                    kt = 1;
                    break;
                }
                s = x / i,p = i;
                b = (s+p-1)/2;
                a = s - b;
                if(a > 0 && b > 0 && a != b) {
                    cout << a << ' ' << b << '\n';
                    kt = 1;
                    break;
                }
            }
        }
        if(!kt) cout << -1 << '\n';
    }
    return 0;
}