#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 2e5+7;
int x[MAXN];
vector<int> dp;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
    }
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(dp.begin(),dp.end(),x[i])-dp.begin();
        if(pos == dp.size()) dp.push_back(x[i]);
        else dp[pos] = x[i];
    }
    cout << dp.size();
    return 0;
}