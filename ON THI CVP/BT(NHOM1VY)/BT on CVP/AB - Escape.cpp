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
    double vp,vd,t,f,c;
    cin >> vp >> vd >> t >> f >> c;
    if(vp >= vd) {
        cout << 0;
        return 0;
    }
    double ans = 0,d1 = vp*t;
    while(d1 < c) {
        double t1 = d1/(vd-vp);
        d1 += vp*t1;
        if(d1 >= c) break;
        ans++;
        d1 += (f+d1/vd) * vp;
    }
    cout << ans;
    return 0;
}