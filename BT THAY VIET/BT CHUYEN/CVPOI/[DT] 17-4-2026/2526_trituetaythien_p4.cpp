#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 5e3 + 7;
int a[MM],b[MM],dp[MM][MM];

int nextval(int i,int j)
{
    if((i % 2) == (j % 2)) return j + 2;
    return j + 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,m; 
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        // cout << a[i] << ' ';
    } 
    // cout << '\n';
    cin >> m;
    for(int i = 0;i < m;i++) {
        cin >> b[i];
        // cout << b[i] << ' ';
    } 
    // cout << '\n';


    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= m;j++)
            dp[i][j] = oo;

    dp[0][0] = 0;
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= m;j++) {
            dp[i+1][j] = min(dp[i+1][j],nextval(a[i],dp[i][j]));
            dp[i][j+1] = min(dp[i][j+1],nextval(b[j],dp[i][j]));
        }
    
    // for(int i = 0;i <= n;i++)
    //     for(int j = 0;j <= m;j++) {
    //         cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    //     }
            
    // cout << nextval(1,2);
    cout << dp[n][m];
    return 0;
}