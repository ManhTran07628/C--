#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,x[MM],dp[MM];
vector<int> v;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
        sum += x[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = sum;j >= x[i];j--) {
            if(dp[j-x[i]]) dp[j] = 1;
        }
    }
    for(int i = 1;i <= sum;i++) {
        if(dp[i]) v.push_back(i);
    }
    cout << v.size() << '\n';
    for(auto i:v) cout << i << ' ';
    return 0;
}