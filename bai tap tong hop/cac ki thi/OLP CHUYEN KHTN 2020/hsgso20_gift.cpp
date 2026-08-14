#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 300 + 7;
const int MOD = 1e9 + 7;
const int offset = 9e4;
int n,k;
int L[MM],R[MM];
int dp[MM][(int) 2e5 + 7];

int addmod(int x,int y)
{
    x += y;
    if(x >= MOD) x -= MOD;
    return x;
}

int minusmod(int x,int y)
{
    return ((x % MOD - y % MOD) + MOD) % MOD;
}

namespace subtask12
{
    int min_lim = 0,max_lim = 0;
    int f(int t)
    {
        for(int i = 0;i <= n;i++)
            for(int j = 0;j < (int) 2e5 + 2;j++)
                dp[i][j] = 0;
        
        dp[0][offset] = 1;
        for(int i = 0;i < n;i++)
            for(int j = min_lim;j <= t;j++) {
                for(int a = L[i+1];a <= R[i+1];a++) {
                    int max_sum = max(a,j + a);
                    if(max_sum <= t) 
                        dp[i+1][max_sum + offset] = addmod(dp[i+1][max_sum + offset],
                            dp[i][j + offset]);
                }
            }

        int res = 0;
        for(int psum = min_lim;psum <= t;psum++) 
            res = addmod(res,dp[n][psum + offset]);
        return res;
    }


    void solve()
    {
        min_lim = -offset;
        for(int i = 1;i <= n;i++) max_lim += R[i];
        cout << (f(k) - f(k-1) + MOD) % MOD;
    }
}

namespace subtask3
{
    int min_lim = 0,max_lim = 0;
    int diff[(int) 2e5 + 7];
    int f(int t)
    {
        for(int i = 0;i <= n;i++)
            for(int j = 0;j < (int) 2e5 + 2;j++)
                dp[i][j] = 0;
        
        dp[0][offset] = 1;
        for(int i = 0;i < n;i++) {

            for (int j = 0; j < offset * 2; j++) diff[j] = 0;

            int sum = 0;
            for(int j = min_lim;j < 0;j++) {
                sum = addmod(sum,dp[i][j + offset]);
            }

            diff[ L[i+1] + offset ] = addmod(diff[ L[i+1] + offset ],sum);
            diff[ R[i+1] + offset + 1 ] = minusmod(diff[ R[i+1] + offset + 1 ],sum);
            
            for(int j = 0;j <= t;j++) {
                int nxt_L = L[i+1] + offset + j;
                int nxt_R = R[i+1] + offset + j + 1;
                diff[nxt_L] = addmod(diff[nxt_L],dp[i][j + offset]);
                diff[nxt_R] = minusmod(diff[nxt_R],dp[i][j + offset]);
            }

            sum = 0;
            for(int j = min_lim;j <= t;j++) {
                sum = addmod(sum,diff[j + offset]);
                dp[i+1][j + offset] = addmod(dp[i+1][j + offset],sum);
            }
            
        }

        int res = 0;
        for(int psum = min_lim;psum <= t;psum++) 
            res = addmod(res,dp[n][psum + offset]);
        return res;
    }


    void solve()
    {
        min_lim = -offset;
        cout << (f(k) - f(k-1) + MOD) % MOD;
    }
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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> L[i] >> R[i];
    subtask3::solve();
    return 0;
}