#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int a[MM],n,cnt[MM];

void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[ a[i] ]++;
    }
}

void solve()
{
    int ans = 0;
    int d1 = min(cnt[3],cnt[1]);
    ans += d1;
    cnt[3] -= d1;
    cnt[1] -= d1;

    int d2 = ceil(cnt[2] / 2);
    ans += d2;
    cnt[2] -= d2 * 2;

    int d3 = min(cnt[2],(int) ceil(cnt[1]/2.0));
    ans += d3;
    cnt[2] -= d3;
    cnt[1] -= min(cnt[1],d3 * 2);

    int d4 = ceil(cnt[1] / 4.0);
    ans += d4;
    cnt[1] -= min(cnt[1],d4 * 4);

    ans += cnt[1] + cnt[2] + cnt[3] + cnt[4];
    cout << ans;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "AODAI"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    solve();
    return 0;
}