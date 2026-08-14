#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int cntdivs[MAXN],ps[MAXN];
void sanguoc()
{
    for(int i = 1;i < MAXN;i++)
        for(int j = i;j < MAXN;j+=i)
            cntdivs[j]++;
}

void solve()
{
    sanguoc();
    int t;
    cin >> t;
    for(int i = 1;i < MAXN;i++) {
        ps[i] = ps[i-1] + (cntdivs[i] == 4);
    }
    while(t--) {
        int l,r;
        cin >> l >> r;
        cout << ps[r] - ps[l-1] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}