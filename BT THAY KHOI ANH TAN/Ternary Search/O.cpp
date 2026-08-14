#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n;
double a[MM],Max[MM],Min[MM];

double f(double x)
{
    double ans = 0;
    for(int i = 1;i <= n;i++) {
        Max[i] = max(Max[i-1] + a[i] - x,a[i] - x);
        Min[i] = min(Min[i-1] + a[i] - x,a[i] - x);
        ans = max({ ans , fabs(Max[i]) , fabs(Min[i]) });
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    double L = *min_element(a+1,a+n+1), R = *max_element(a+1,a+n+1);
    for(int i = 1;i <= 100;i++) {
        double m1 = L + (R - L) / 3.0, m2 = R - (R - L) / 3.0;
        if(f(m1) > f(m2)) L = m1;
        else R = m2;
    }
    cout << fixed << setprecision(15) << f(L);
    return 0;
}