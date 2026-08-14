#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
double xA,yA,xB,yB,xC,yC,xD,yD;
int t;

double cntdist(double k)
{
    double NxA = xA + (xB - xA) * k / 100;
    double NyA = yA + (yB - yA) * k / 100;

    double NxC = xC + (xD - xC) * k / 100;
    double NyC = yC + (yD - yC) * k / 100;

    double diff = sqrt( (NxA - NxC) * (NxA - NxC) + (NyA - NyC) * (NyA - NyC) );
    return diff;
}

void solve()
{
    cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD;
    double l = 0,r = 100;
    for(int i = 1;i <= 100;i++) {
        double m1 = l + (r-l) / 3.0, m2 = r - (r-l) / 3.0;
        if(cntdist(m1) < cntdist(m2)) r = m2;
        else l = m1;

    }
    cout << fixed << setprecision(6) << cntdist(l) << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}