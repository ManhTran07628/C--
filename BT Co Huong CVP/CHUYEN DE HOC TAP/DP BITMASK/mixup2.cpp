#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 16;
int n,k;
int a[MM];
ll dp[1 << MM][MM + 7];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> a[i];
    // dp[0][0] = 1;


    for(int i = 0;i < n;i++)
        dp[1 << i][i] = 1;


    for(int mask = 1;mask < (1 << n);mask++) {
        // cout << mask << ' ';
        vector<int> valid;
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                valid.push_back(i);
                // cout << i << ' ';
            }
        }
        for(auto i:valid) {
            for(auto j:valid) {
                if(i == j) continue;
                if(abs( a[j] - a[i] ) > k ) {
                    int pmask = mask ^ (1 << j);
                    dp[mask][j] = (dp[mask][j] + dp[pmask][i]);
                    // cout << dp[pmask][i] << ' ';

                }

            }
        }
        // cout << '\n';
        

    }
    ll res = 0;
    for(int i = 0;i < n;i++) 
        res = (res + dp[ (1 << n) - 1 ][i]);
    cout << res;
    return 0;
}