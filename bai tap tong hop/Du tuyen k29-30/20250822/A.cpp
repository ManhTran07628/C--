#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 1e9+7;
int n,m;
ll dp[1007][1 << 10];
vector<int> valid_mask;
void Try(int mask,int next_mask,int id)
{
    if(id == n) {
        valid_mask.push_back(next_mask);
        return;
    }
    if(mask & (1 << id)) Try(mask,next_mask,id+1);
    else {
        if(id+2 <= n && !(mask >> (id+1) & 1) )  Try(mask,next_mask,id+2);
        if(id+1 <= n) Try(mask,next_mask | (1 << id),id+1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dp[0][0] = 1;
    for(int j = 0;j < m;j++) {
        for(int mask = 0;mask < (1 << n);mask++) {
            Try(mask,0,0);
            for(auto next_mask:valid_mask) {
                dp[j+1][next_mask] += dp[j][mask];
                dp[j+1][next_mask] %= MOD;
            }
            valid_mask.clear();
        }
    }
    cout << dp[m][0];
    return 0;
}