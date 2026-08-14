#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<pair<ll, ll>> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define taskname "milk"
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll a1, a2;
        cin >> a1 >> a2;
        a.push_back({a1, a2});
    }
    sort(a.begin(), a.end());
    // for(auto c:a) {
    //     cout << c.first << " " << c.second << '\n';
    // }
    ll sua = 0, ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (sua + a[i].second < n)
        {
            k
                sua += a[i].second;
            ans += a[i].first * a[i].second;
        }
        else
        {
            ans += (n - sua) * a[i].first;
            break;
        }
    }
    cout << ans;
    return 0;
}