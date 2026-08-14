#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 200 + 7;
const double PI = acos(-1);
double f[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "math1"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    int i = 0;
    double res = 0;
    for(double x = -1.5;x <= 100;x += 0.5) {
        if(x < 0) {
            double val = cos(4.5 * x * x) + 5 * sin(x * x * x - 1);
            if(val > n) {
                f[++i] = val;
                res += val;
            }
        }
        else if(x == 0.0) {
            double val = 7;
            if(val > n) {
                f[++i] = val;
                res += val;
            }
        }
        else if(x > 0) {
            double val = log2(x) + sqrt(x*x + 5.0);
            if(val > n) {
                f[++i] = val;
                res += val;
            }
        }
    }
    sort(f+1,f+i+1);
    int sz = i;
    cout << fixed << setprecision(9) << res << '\n';
    for(int i = 1;i <= sz;i++) cout << fixed << setprecision(9) << f[i] << ' ';
    return 0;
}