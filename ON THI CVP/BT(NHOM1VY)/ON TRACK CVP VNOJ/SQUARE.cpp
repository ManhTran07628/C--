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
    int n;
    cin >> n;
    ll x1 = 1e12,y1 = 1e12,x2 = 0,y2 = 0;
    for(int i = 1;i <= n;i++) {
        ll u,v;
        cin >> u >> v;
        x1 = min(x1,u);
        x2 = max(x2,u);
        y1 = min(y1,v);
        y2 = max(y2,v);
    }
    ll c = max(y2-y1,x2-x1);
    ll ans = abs(c)*abs(c);
    cout << ans;
    return 0;
}