#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 2e6+7;
int cntdiv[MAXN];
int ans = 0,n;

void divsieve()
{
    for(int i = 1;i < MAXN;i++)
        for(int j = i;j < MAXN;j+=i)
            cntdiv[j]++;
}

void solve()
{
    divsieve();
    for(int i = 1;i <= n;i++) {
        int d1 = cntdiv[i];
        int d2 = cntdiv[n-i];
        ans = ans + d1*d2;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
    return 0;
}