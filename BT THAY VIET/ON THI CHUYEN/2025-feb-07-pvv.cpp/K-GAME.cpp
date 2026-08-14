#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N];
int dp[1001][1001];
int n;
void jump(int dt,int st,int j)
{
    if(dt == 1 && st == 1) {
        dp[2][0] = a[2];
        jump(dt+1,st+1,j);
        return;
    }
    if(dt == n) {
        exit(0);
    }
    if(dt+st+1 <= n) {
        dp[dt+st+1][j] = dp[dt][j] + a[dt+st+1];
        jump(dt+st+1,st+1,j);
    }
    if(dt-st >= 1) {
        dp[dt-st][j+1] = dp[dt][j] + a[dt-st];
        jump(dt-st,st,j+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    jump(1,1,0);
    for(int i = 0;i <= 100;i++) {
        if(dp[n][i] != 0) cout << dp[n][i] << ' ' << i << '\n';
    }
    return 0;
}