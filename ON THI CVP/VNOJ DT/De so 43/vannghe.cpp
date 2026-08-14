#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll s[N],t[N],c[N],dp[N];
pair<pair<ll,ll>,ll> pa[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "vannghe"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> pa[i].fi.fi >> pa[i].fi.se >> pa[i].se;
    }
    sort(pa+1,pa+m+1);
    // for(int i = 1;i <= m;i++) {
    //     cout << pa[i].fi.fi << " " << pa[i].fi.se << " " << pa[i].se << '\n';
    // }
    fill(dp,dp+n+1,1e9);
    dp[0] = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = pa[i].fi.fi;j <= pa[i].fi.se;j++) {
            dp[j] = min(dp[j],dp[pa[i].fi.fi] + pa[i].se);
        }
    }
    cout << dp[n];
    return 0;
}