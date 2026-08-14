#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,k,dp[MM][21][3];
char a[MM],st[3] = {'H','S','P'};
// dp[i][k][t] : so luot thang nhieu nhat khi bat dau chon doi
// tu the k lan va tu the chon la t
// H - 0    S - 1    P - 2
// H -> S
// S -> P
// P -> H

bool win(char x,char y) {
    if(x == 'H' && y == 'S') return 1;
    if(x == 'S' && y == 'P') return 1;
    if(x == 'P' && y == 'H') return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "hps"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 0;i < 3;i++) {
        dp[1][0][i] = win(st[i],a[1]);
    }
    for(int i = 2;i <= n;i++) {
        for(int j = 0;j <= k;j++) {
            for(int t = 0;t < 3;t++) {
                dp[i][j][t] = max(dp[i][j][t],dp[i-1][j][t]+win(st[t],a[i]));
                if(j > 0) {
                    for(int pt = 0;pt < 3;pt++) {
                        if(t == pt) continue;
                        dp[i][j][t] = max(dp[i][j][t],dp[i-1][j-1][pt]+win(st[t],a[i]));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0;j <= k;j++) 
        for(int i = 0;i < 3;i++) 
            ans = max(ans,dp[n][j][i]);
    cout << ans;
    // cout << dp[1][0][0] << ' ' << dp[1][0][1] << ' ' << dp[1][0][2];
    return 0;
}