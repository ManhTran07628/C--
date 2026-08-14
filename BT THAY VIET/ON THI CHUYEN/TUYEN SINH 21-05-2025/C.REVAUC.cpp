#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN];
map<int,pair<int,int>> counts;

void solve()
{
    int ans = 0;
    for(auto i:counts) {
        if(i.se.fi == 1) {
            cout << i.se.se;
            return;
        }
    }
    for(auto i:counts) {
        cout << i.se.se;
        return;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        counts[a[i]].fi++;
        if(counts[a[i]].se == 0) counts[a[i]].se = i;
    }
    solve();
    return 0;
}