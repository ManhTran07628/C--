#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 7;
ll a[N], b[N];
ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define taskname ""
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    ll n;
    cin >> n;
    ll c2 = 0, c5 = 0, c0 = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0) c2++;
        if (a[i] % 5 == 0) c5++;
        if (a[i] % 10 == 0) c0++;
    }
    ll a2 = c2;
    ll a5 = c5;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] % 10 == 0)
        {
            c0--;
            ans += n - a2 - a5 + c0;
        }
        if (a[i] % 2 == 0)
        {
            ans += c5;
            c2--;
        }
        if (a[i] % 5 == 0)
        {
            ans += c2;
            c5--;
        }
    }
    cout << ans;
    return 0;
}

// 10
// 8 2 0 5 2 0 6 5 5 2
// //4
// 3 2 0 10
