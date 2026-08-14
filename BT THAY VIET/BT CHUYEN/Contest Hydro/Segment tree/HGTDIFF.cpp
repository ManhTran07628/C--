#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e4+7;
const int LOG = 16;
int n,q,h[MM],Max[MM][LOG+1],Min[MM][LOG+1];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
        Max[i][0] = Min[i][0] = h[i];
    }
}

void process()
{
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            Max[i][j] = max(Max[i][j-1],Max[i + (1 << (j-1)) ][j-1]);
            Min[i][j] = min(Min[i][j-1],Min[i + (1 << (j-1)) ][j-1]);
        }
    }
}

int query(int l,int r)
{
    int k = __lg(r-l+1);
    int minLR = min(Min[l][k],Min[r - (1 << k) + 1][k]);
    int maxLR = max(Max[l][k],Max[r - (1 << k) + 1][k]);
    return maxLR - minLR;
}   

void solve()
{
    process();
    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << query(a,b) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}