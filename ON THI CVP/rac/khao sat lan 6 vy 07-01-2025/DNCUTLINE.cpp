#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 7;
int b[N], x, y;
vector<pair<int, int>> v, v1;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.fi == b.fi)
        return (a.se > b.se);
    return (a.fi < b.fi);
}
int tk(int i, int j, int k)
{
    int l = i;
    int r = j;
    int ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (b[mid] < k)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
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
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> y >> x;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        int t = tk(0, ans, v[i].se);
        b[t + 1] = v[i].se;
        ans = max(ans, t + 1);
    }
    cout << ans;
    return 0;
}