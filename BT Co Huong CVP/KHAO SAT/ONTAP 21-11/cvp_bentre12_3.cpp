#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 100+7;
int n,m;
int c[MM][MM];
struct dl{ll val;int trace[MM];} dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "messages"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        dp[i].val = oo;
        for(int j = 1;j <= m;j++) dp[i].trace[j] = 0;
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {

            for(int s = n;s >= i;s--) {
                if(dp[s - i].val + c[i][j] < dp[s].val) {
                    dp[s].val = dp[s - i].val + c[i][j];


                    for(int k = 1;k <= m;k++) 
                        dp[s].trace[k] = dp[s - i].trace[k];
                        
                    dp[s].trace[j] += i;

                }
            }

        }
    }
    cout << dp[n].val << '\n';
    for(int i = 1;i <= m;i++) {
        cout << dp[n].trace[i] << '\n';
    }
    return 0;
}