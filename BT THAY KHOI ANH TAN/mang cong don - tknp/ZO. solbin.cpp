#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 2000+7;
int a[MAXN][MAXN];
int n,m;
int d=1,c=1;
void prefix()
{
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            a[i+n][j] = a[i][j];
            a[i+n][j+m] = a[i][j];
            a[i][j+m] = a[i][j];
        }
    for(int i = 1;i <= n+n;i++) 
        for(int j = 1;j <= m+m;j++)  a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
}
void type1()
{
    int x,y;
    cin >> x >> y;
    d = (d+x);
    c = (c+y);
    while(d > m) d -= m;
    while(c > n) c -= n;
}

void type2()
{
    int u,v,s,t;
    cin >> u >> v >> s >> t;
    u += c-1;
    v += d-1;
    s += c-1;
    t += d-1;
    int ans = a[s][t]-a[s][v-1]-a[u-1][t]+a[u-1][v-1];
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    prefix();
    int q;
    cin >> q;
    while(q--) {
        int p;
        cin >> p;
        if(p == 0) type1();
        else type2();
    }
    return 0;
}