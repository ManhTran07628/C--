#include <bits/stdc++.h>
#define ll long long
#define se second
#define fi first
using namespace std;
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
ll n, t, a[N], ans, k, diff, d, mn[21][N], mx[21][N];
map<ll,ll>vis;
void Ma()
{
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) <= n; i++)
        {
            mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
        }
    }
}
void Mi()
{
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) <= n; i++)
            mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
    }
}
ll queryMA(ll l, ll r)
{
    ll k = 63 - __builtin_clzll(r - l + 1);
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
ll queryMI(ll l, ll r)
{
    ll k = 63 - __builtin_clzll(r - l + 1);
    return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}

ll query(ll l, ll r)
{
    ll k = 63 - __builtin_clzll(r - l + 1);
    return max(mx[k][l], mx[k][r - (1 << k) + 1]) - min(mn[k][l], mn[k][r - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #define taskname "B00493"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }

    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn[0][i] = a[i];
        mx[0][i] = a[i];
    }
    Mi();
    Ma();
    ll l = 1;
    ll mi = 1e18, ma = -1e18;
    map<ll, ll> cnt;
    for (ll r = 1; r <= n; r++)
    {
        cnt[a[r]]++;
        if (!vis[a[r]])
        {
            vis[a[r]] = true;
            diff++;
        }
        while (query(l, r) > k || diff > d)
        {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
            {
                diff--;
                vis[a[l]] = false;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}