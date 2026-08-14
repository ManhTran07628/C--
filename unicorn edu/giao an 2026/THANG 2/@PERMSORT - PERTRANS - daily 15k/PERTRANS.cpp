#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long n, p, m, a[N], b[N];
int main()
{
    cin >> n >> p >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    long long ans=0;
    for (int i=1; i<=n; i++)
    if (a[i] > b[i]) ans += (a[i]-b[i])*m;
    else ans += (b[i]-a[i])*p;
    cout << ans;
    return 0;
}