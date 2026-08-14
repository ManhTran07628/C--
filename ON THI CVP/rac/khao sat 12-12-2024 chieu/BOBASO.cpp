#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BOBASO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a1 = 0,b1 = 0,c1 = 0,ans = 0;
        for(ll a = 1;a <= n;a++) {
            for(ll b = a+1;b + a <= n;b++) {
                ll c = n - a - b;
                if(c != a && c != b && c > 0) {
                    ll res = __gcd(a,b);
                    if(res == c) {
                        ll tmp = a*b*c;
                        if(tmp >= ans) {
                            a1 = a;b1 = b;c1 = c;
                            ans = a*b*c;
                        }
                    }
                }
            }
        }
        cout << a1 << " " << b1 << " " << c1 << '\n';
    }
    return 0;
}