#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,q;
ll a[MM],g[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= q;i++) {
        int l,r;
        cin >> l >> r;
        a[l] += l - 1;
        a[r + 1] -= (l - 1);
        g[l]++;
        g[r + 1]--;
    }

    for(int i = 1;i <= n;i++) {
        a[i] += a[i-1];
        g[i] += g[i-1];
        cout << g[i] * i - a[i] << ' ';
    }

    return 0;
}