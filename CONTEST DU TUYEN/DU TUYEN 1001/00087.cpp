#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 270+7;
int n,k,newk;
int a[MM][MM],dp[MM][MM][2];

void compress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    if(k > v.size()) k = v.size() + 1;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++) {
            a[i][j] = lower_bound(v.begin(),v.end(),a[i][j]) - v.begin() + 1;
        }
}

bool check(int x,int y)
{
    map<int,int> mp;
    for(int i = x-1;i <= x;i++) 
        for(int j = y-1;j <= y;j++) 
            mp[ a[i][j] ]++;
            // cout << a[i][j] << ' ';
        
        // cout << '\n';
    
    // cout << '\n';
    return mp.size() >= 3;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];
    compress();

    int res = 0;
    for(int i = 2;i <= n;i++)
        for(int j = 2;j <= n;j++) {
            
            // khong doi
            dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][0]);
            dp[i][j+1][0] = max(dp[i][j+1][0],dp[i][j][0]);
            dp[i+1][j+1][0] = max(dp[i+1][j+1][0],dp[i][j][0]);

            if(check(i,j)) {
                dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][0] + 1);
                dp[i][j+1][0] = max(dp[i][j+1][0],dp[i][j][0] + 1);
                dp[i+1][j+1][0] = max(dp[i+1][j+1][0],dp[i][j][0] + 1);
            }
            
            // co doi
            for(int u = i-1;u <= i;u++) 
                for(int v = j-1;v <= j;v++) {

                    int fval = a[u][v];
                    for(int x = 1;x <= k;x++) {
                        if(fval == x) continue;
                        a[u][v] = x;
                        if(check(i,j)) {
                            dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][1] + 1);
                            
                            dp[i][j+1][1] = max(dp[i][j+1][1], dp[i][j][1] + 1);
                            
                            dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][1] + 1);
                        }
                        
                    }
                    
                    a[u][v] = fval;

                }

        }

    for(int i = 1;i <= n+1;i++) {
        for(int j = 1;j <= n+1;j++)
            res = max({res,dp[i][j][0],dp[i][j][1]});
    }
    cout << res;

    return 0;
}
