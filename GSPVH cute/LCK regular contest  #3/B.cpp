#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 30 + 7;
int d,s,l[MM],r[MM];
struct Node
{
    int val;
    string trace;
} dp[MM][241];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "honeymoon"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> d >> s;
    for(int i = 1;i <= d;i++) cin >> l[i] >> r[i];

    for(int i = 0;i <= d;i++) 
        for(int j = 0;j <= s;j++) {
            dp[i][j].val = 0;
            dp[i][j].trace = "";
        }

    dp[0][0].val = 1;
    for(int i = 1;i <= d;i++) {
        for(int val = l[i];val <= r[i];val++) {
            for(int k = s;k >= val;k--) {
                if(dp[i - 1][k - val].val == 0) continue;
                dp[i][k].val = 1;
                char c = val + '0';
                dp[i][k].trace = dp[i - 1][k - val].trace + c;

            }
        }
    }
    
    if(dp[d][s].val == 1) {
        cout << "YES" << '\n';
        for(auto c:dp[d][s].trace) cout << c << ' ';
    }
    else cout << "NO";
    return 0;
}