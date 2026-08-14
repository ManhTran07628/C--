#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int t,n,a[MM],vis[MM];

void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

void solve()
{
    // memset(vis,0,sizeof(vis));
    sort(a+1,a+n+1,greater<int>());
    int i = 1,j = 1,pp = 0;
    while(j <= n) {
        while(i <= n && vis[i]) i++;
        if(a[j] * 2 <= a[i]) {
            vis[j] = 1;
            pp++;
            i++; j++;
        }
        else if(a[j] * 2 > a[i]) {
            j++;
        }
    }
    cout << n-pp << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        init();
        solve();
    }
    return 0;
}