#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 17;
ll n,a[MM][MM],g[1 << 16],dp[1 << 16];
vector<int> valid_mask[1 << 16];
void Try(int mask,int new_mask,int id)
{
    if(id == n) {
        valid_mask[mask].push_back(new_mask);
        return;
    }
    if(!(mask >> id & 1)) Try(mask,new_mask,id+1);
    else {
        Try(mask,new_mask,id+1);
        Try(mask,new_mask | (1 << id),id+1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
    for(int mask = 1;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) 
                for(int j = i+1;j < n;j++) 
                    if(mask >> j & 1) g[mask] += a[i][j];
        }
        Try(mask,0,0);
    }

    for(int mask = 1;mask < (1 << n);mask++) {
        for(auto prev_mask:valid_mask[mask]) {
            dp[mask] = max(dp[mask],dp[prev_mask] + g[mask ^ prev_mask]);
        }
    }
    cout << dp[(1 << n)-1];
    return 0;
}