#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TOWERS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    if(a == b) {
        cout << a * x + b * y;
        return 0;
    }
    ll t1 = max(x,y);
    ll t2 = min(x,y);
    ll ans = 0;
    if(t2 + 1 <= t1) {
        if(a == t1) {
            ans = (t2+1)*x + t2 * y;
        }
        else ans = (t2+1)*x + t2 * x;
    }
    cout << ans;
    return 0;
}