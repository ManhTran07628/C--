#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x = -1,y = 1e15,n,kt = 1;
    cin >> n;
    while(n--) {
        ll v,d;
        cin >> v >> d;
        if(x == -1) {
            x = max(x,d+v);
            y = min(y,abs(d-v));
            continue;
        }
        if(v - x > d || y - v > d) kt = 0;
        else {
            x = min(x,v+d);
            y = min(y,v-d);
        }
    }
    if(kt) cout << x;
    else cout << -1;
    return 0;
}