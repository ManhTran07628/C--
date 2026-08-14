#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 507;
int n,k,dp[MM],c[MM];
vector<int> v;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    dp[0] = 1;
    v.push_back(0);
    for(int i = 1;i <= n;i++) {
        for(int j = k;j >= c[i];j--) {
            if(dp[j-c[i]]) {
                dp[j] = 1;
            }
        }
    }
    for(int i = 1;i <= k;i++) {
        if(dp[i]) v.push_back(i);
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(auto i:v) cout << i << ' ';
    return 0;
}