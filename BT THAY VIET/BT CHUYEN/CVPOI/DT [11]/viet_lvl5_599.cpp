#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,b,f[MM],dp[MM];    

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> b;
    for(int i = 1;i <= n;i++) cin >> f[i];
    while(b--) {
        int s,d; cin >> s >> d;
        // cout << s << ' ' << d << '\n';
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        for(int i = 1;i <= n;i++) {
            if(!dp[i]) continue;
            for(int j = i + 1;j <= n;j++) {
                if(j - i <= d && s >= f[j]) dp[j] = 1;
            }
        }
        cout << (dp[n] == 1 ? 1 : 0) << '\n';
    }
    return 0;
}