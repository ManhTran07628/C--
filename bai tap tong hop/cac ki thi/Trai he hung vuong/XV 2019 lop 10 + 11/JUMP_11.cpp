#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
const int MOD = 1e9 + 7;
int num_row,num_col,k,a[MM],b[MM],c[MM][MM];
ll dp[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> num_row >> num_col >> k;
    for(int i = 1;i <= num_row;i++) cin >> a[i];
    for(int i = 1;i <= num_col;i++) cin >> b[i];

    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) 
            c[i][j] = 1 + (a[i] + b[j]) % k;

    dp[1][1] = 1;
    for(int i = 1;i <= num_row;i++) {
        for(int j = 1;j <= num_col;j++) {

            cout << c[i][j] << ' ';

            for(int u = i;u <= num_row;u++) {
                if(u - i > c[i][j]) break;
                for(int v = j;v <= num_col;v++) {
                    if(i == u && j == v) continue;
                    if(u + v - i - j > c[i][j]) break;
                    dp[u][v] = (dp[u][v] + dp[i][j]) % MOD;
                }
            }

        }
        cout << '\n';
    }

    cout << dp[num_row][num_col];

    return 0;
}