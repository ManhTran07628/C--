#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
const int MOD = 1e9 + 7;
int n,m;
ll dp[MM][1 << 10];
vector<int> valid;

void Try(int i,int mask,int new_mask,vector<int> &valid)
{
    if(i == n) {
        valid.push_back(new_mask);
        return;
    }
    if((mask >> i) & 1) Try(i+1,mask,new_mask,valid);
    else {
        Try(i+1,mask,new_mask | (1 << i),valid);
        if(i+1 < n && !((mask >> (i + 1)) & 1)) 
            Try(i+2,mask,new_mask,valid);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    // vector<int> v;
    // Try(0,33,0,v);
    // bitset<7> d = 33;
    // cout << d << '\n';
    // for(auto x:v) {
    //     bitset<7> f = x;
    //     cout << f << '\n';
    // }
    dp[0][0] = 1;

    for(int j = 0;j < m;j++) {

        for(int mask = 0;mask < (1 << n);mask++) {

            Try(0,mask,0,valid);

            for(auto new_mask:valid) 
                dp[j+1][new_mask] = (dp[j+1][new_mask] + dp[j][mask]) % MOD;
            valid.clear();
        }

    }

    cout << dp[m][0];

    return 0;
}