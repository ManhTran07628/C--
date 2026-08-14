#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
const int MOD = 1e9+7;
int dp[1001][1 << 11]; 
int n,m;
vector<int> res;
// dp[i][mask] so cach dien day cac cot tu 0 den i-1 va trang thai cot 
// ans = dp[m][0] 
vector<int> dx{2,0};
vector<int> dy{0,2};

void backtrack(int pos,int mask,int next_mask,int n)
{
    if(pos == n) {
        res.push_back(next_mask);
        return;
    }
    if((mask >> pos) & 1) {
        backtrack(pos+1,mask,next_mask,n);
    }
    else {
        backtrack(pos+1,mask,next_mask | (1 << pos),n);
        if(pos+1 < n && !((mask >> (pos+1)) & 1)) {
            backtrack(pos+2,mask,next_mask,n);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dp[0][0] = 1;

    for(int i = 0;i < m;i++) {
        for(int mask = 0;mask < (1 << n);mask++) {
            backtrack(0,mask,0,n);
            for(auto next_mask:res) {
                dp[i+1][next_mask] += dp[i][mask];
                dp[i+1][next_mask] %= MOD;
            }
            res.clear();
        }
    }
    cout << dp[m][0];
    return 0;
}