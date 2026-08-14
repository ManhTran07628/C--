#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define taskname "DRB"
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    ll s1, s2, v1, v2;
    cin >> s1 >> v1 >> s2 >> v2;
    if (v1 == v2)
    {
        cout << "-1";
    }
    float t = float(s2 - s1) / (v1 - v2);
    if (t < 0)
        cout << -1;
    else {
        ll ans = floor(t);
        cout << ans;
    }
    return 0;
}