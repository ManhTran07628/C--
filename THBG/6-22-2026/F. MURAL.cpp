#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
ll n,a[MM],b[MM];


namespace subtask12
{
    int dp[501][501];
    map<int,int> mp;
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            dp[i][1] = a[i];
            dp[1][i] = b[i];
            mp[ a[i] ]++;
            if(i != 1)
                mp[ b[i] ]++;
        } 

        for(int i = 2;i <= n;i++)
            for(int j = 2;j <= n;j++) {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                mp[ dp[i][j] ]++;
            }

        int max_val = 0, cnt = 0;
        for(auto E:mp) {
            if(cnt < E.se) {
                max_val = E.fi;
                cnt = E.se;
            }
        }
        for(auto E:mp) {
            if(cnt == E.se) {
                max_val = max(max_val,E.fi);
            }
        }
        cout << max_val << ' ' << cnt;
    }
}

namespace sol
{
    int row[MM],col[MM];
    map<ll,ll> mp;
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            mp[ a[i] ]++;
            if(i > 1) 
               mp[ b[i] ]++;
        }
        
        for(int i = 3;i <= n;i++) a[i] = max(a[i-1],a[i]);
        for(int i = 3;i <= n;i++) b[i] = max(b[i-1],b[i]);


        for(int i = 2;i <= n;i++) {
            row[i] = upper_bound(b+2,b+n+1,a[i]) - b - 2;
            mp[ a[i] ] += row[i];

            col[i] = lower_bound(a+2,a+n+1,b[i]) - a - 2;
            mp[ b[i] ] += col[i];
        }
        
        ll max_val = 0, cnt = 0;
        for(auto E:mp) {
            if(cnt < E.se) {
                max_val = E.fi;
                cnt = E.se;
            }
        }
        for(auto E:mp) {
            if(cnt == E.se) {
                max_val = max(max_val,E.fi);
            }
        }
        cout << max_val << ' ' << cnt;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "sol"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    //  subtask12::solve();
    sol::solve();
    return 0;
}