#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N], b[N], f[N][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define taskname "ZIGZAG"
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    ll ma = 0,maa = 0,mbb = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = max(a[i],mbb+a[i]);
        f[i][1] = max(b[i],maa+b[i]);
        ma = max({ma,f[i][0],f[i][1]});
        maa = max(maa,f[i][0]);
        mbb = max(mbb,f[i][1]);
    }
    cout << ma << "\n";
    return 0;
}
