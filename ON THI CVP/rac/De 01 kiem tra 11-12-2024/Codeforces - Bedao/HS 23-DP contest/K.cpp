#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string x,y;
    cin >> x >> y;
    for(int i = 0;i < x.size();i++) {
        for(int j = 0;j < y.size();j++) {
            if(x[i] == y[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout << dp[x.size()][y.size()];
    return 0;
}