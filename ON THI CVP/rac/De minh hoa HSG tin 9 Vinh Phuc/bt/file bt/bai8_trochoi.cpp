#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int main()
{
    freopen("trochoi.inp","r",stdin);
    freopen("trochoi.out","w",stdout);
    ll m,n;
    cin >> m >> n;
    ll kq = (m * (n+1)) + (n * (m+1));
    cout << kq;
    return 0;
}
