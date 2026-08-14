#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
double a[N],b[N];
ll tmp = 0;
int main()
{
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll q;
    cin >> q;
    for(int i = 1;i <= q;i++) {
        ll l,r;
        cin >> l >> r;
        double kq = (b[r-1] - b[l-1]) / (r-l);
        cout << fixed << setprecision(6) << kq << endl;
    }

    return 0;
}
