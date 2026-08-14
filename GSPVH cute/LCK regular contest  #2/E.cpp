#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,x[MM],y[MM],t[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> x[i] >> y[i] >> t[i];
    bool ok = 1;
    int u = 0, v = 0;
    for(int i = 1;i <= n;i++) {
        if(abs(x[i] - u) + abs(y[i] - v) <= t[i] - t[i-1]) {
            u = x[i]; v = y[i];
        }
        else {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "YES" : "NO");
    return 0;
}