#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;

struct Node{int a,b,c;} d1,d2;

void calc(int xa,int ya,int xb,int yb,Node &d)
{
    int vtcp_a = (xb - xa), vtcp_b = (yb - ya);
    int vtpt_a = vtcp_b, vtpt_b = -vtcp_a;
    d = {vtpt_a,vtpt_b,-(vtpt_a * xa + vtpt_b * ya)};
}

void solve()
{
    int xa,ya,xb,yb,xc,yc,xd,yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    calc(xa,ya,xb,yb,d1);
    calc(xc,yc,xd,yd,d2);
    int a1 = d1.a, a2 = d2.a;
    int b1 = d1.b, b2 = d2.b;
    // cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << '\n';
    if(1ll * a1 * b2 != 1ll * a2 * b1) {
        cout << "NO" << '\n';
    }
    else cout << "YES" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}