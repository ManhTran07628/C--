#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll dp[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "LONGXAU"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[0][0] = (s[0] == 'a' || s[0] == '?') ? 0 : -1e18;
    dp[0][1] = (s[0] == 'b' || s[0] == '?') ? 0 : -1e18;
    for(int i = 1;i < n;i++) {
        if(s[i] == 'a' || s[i] == '?') dp[i][0] = max(dp[i-1][0],dp[i-1][1]-1);
        if(s[i] == 'b' || s[i] == '?') dp[i][1] = max(dp[i-1][0]+1,dp[i-1][1]);
    }
    cout <<  max(dp[n-1][0],dp[n-1][1]);
    return 0;
}