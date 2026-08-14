#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,q,lg2[MM],stMax[MM][17],stMin[MM][17],a[MM],LG = 16;

void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) {
        lg2[i] = lg2[i/2] + 1;
    }
}


void build() {
    for(int i = 1;i <= n;i++) {
        stMax[i][0] = stMin[i][0] = a[i];
    }
    for(int j = 1;j <= LG;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            stMax[i][j] = max(stMax[i][j-1],stMax[i+(1<<(j-1))][j-1]);
            stMin[i][j] = min(stMin[i][j-1],stMin[i+(1<<(j-1))][j-1]);
        }
    }
}

ll getMax(ll l,ll r)
{
    ll k = lg2[r-l+1];
    return max(stMax[l][k],stMax[r-(1 << k)+1][k]);
}

ll getMin(ll l,ll r)
{
    ll k = lg2[r-l+1];
    return min(stMin[l][k],stMin[r-(1 << k)+1][k]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    BuildLog2Arr();
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build();
    while(q--) {
        ll l,r;
        cin >> l >> r;
        // cout << getMax(l,r) << ' ' << getMin(l,r) << '\n';
        int len = getMax(l,r)-getMin(l,r)+1;
        cout << (len == r-l+1 ? "YES" : "NO") << '\n';
    }
    return 0;
}