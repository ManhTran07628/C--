#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e5+7;
int n,c[MM];
int dp[MM],f[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        sum += c[i];
    }
    for(int i = 1;i <= sum;i++) dp[i] = -oo;
    for(int i = 1;i <= n;i++) {

        for(int x = 0;x <= sum;x++) f[x] = dp[x];

        for(int x = 0;x <= sum;x++) {
            if(x + c[i] <= sum) 
                dp[ x + c[i] ] = max(dp[ x + c[i] ],f[x] + c[i]);
            if(x - c[i] >= 0)
                dp[ x - c[i] ] = max(dp[ x - c[i] ],f[x] + c[i]);
            if(c[i] - x >= 0)
                dp[ c[i] - x ] = max(dp[ c[i] - x ],f[x] + c[i]);

        }
    }
    cout << (sum - dp[0]) + dp[0] / 2;
    return 0;
}   


