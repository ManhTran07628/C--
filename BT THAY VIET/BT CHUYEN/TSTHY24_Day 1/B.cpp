#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7,mod = 2023;
ll n,dp[MM],sz[MM];
struct Inp{
    ll a,b,c,d;
} a[MM];

bool cmp(Inp x,Inp y)
{
    if(x.a != y.a) return x.a < y.a;
    if(x.b != y.b) return x.b < y.b;
    if(x.c != y.c) return x.c < y.c;
    return x.d < y.d;
}

void subtask12()
{
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[j].b < a[i].a && a[j].d < a[i].c) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    ll sizemax = 1,cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(dp[i] == 1) sz[i] = 1;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            if(dp[j] == dp[i]-1 && a[j].b < a[i].a && a[j].d < a[i].c) 
                sz[i] = (sz[i]+sz[j])%mod;
        }
        sizemax = max(sizemax,dp[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(dp[i] == sizemax) cnt = (cnt + sz[i]) % mod;
    }
    cout << sizemax << ' ' << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    }
    sort(a+1,a+n+1,cmp);
    subtask12();
    return 0;
}