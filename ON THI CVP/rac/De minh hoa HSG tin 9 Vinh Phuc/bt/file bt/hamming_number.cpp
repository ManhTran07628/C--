#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N];

ll sls(ll k)
{
    return k / 2 + k / 3 + k / 5 - k / 6 - k / 15 - k / 10 + k / 30;
}

ll tknp(ll k, ll n)
{
    ll L = 1, R = n * 3, mid;
    while (L <= R)
    {
        mid = (L + R) / 2;
        if (sls(mid) == k)
            return mid;
        else if (sls(mid) > k)
            R = mid - 1;
        else
            L = mid + 1;
    }
    return mid;
}

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
    ll q;
    cin >> q;
    while (q--)
    {
        ll m;
        cin >> m;
        ll x = tknp(m, m);
        while (x % 5 != 0 && x % 3 != 0 && x % 7 != 0)
            x--;
        cout << x << '\n';
    }
    return 0;
}