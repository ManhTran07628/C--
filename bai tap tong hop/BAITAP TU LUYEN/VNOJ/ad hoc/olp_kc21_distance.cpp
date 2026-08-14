#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,m,k,a[MM],b[MM],lg2[MM],c[MM],stMin[MM][17],LG = 16;

void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) {
        lg2[i] = lg2[i/2] + 1;
    }
}

void stBuild()
{
    BuildLog2Arr();
    for(int i = 1;i <= m;i++) {
        stMin[i][0] = c[i];
    }
    for(int j = 1;j <= LG;j++) {
        for(int i = 1;i + (1 << j) - 1 <= m;i++) {
            stMin[i][j] = min(stMin[i][j-1],stMin[i + (1 << (j-1))][j-1]);
        }
    }
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
    cin >> m >> n >> k;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    sort(b+1,b+n+1);
    for(int i = 1;i <= m;i++) {
        ll temp = oo;
        ll pos = lower_bound(b+1,b+n+1,a[i])-b;
        temp = min(temp,abs(b[pos]-a[i]));
        if(pos > 1) temp = min(temp,abs(b[pos-1]-a[i]));
        if(pos < n) temp = min(temp,abs(b[pos+1]-a[i]));
        c[i] = temp;
    }
    stBuild();
    while(k--) {
        ll l,r;
        cin >> l >> r;
        cout << getMin(l,r) << '\n';
    }
    return 0;
}