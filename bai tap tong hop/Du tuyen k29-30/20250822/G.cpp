#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,a[MM],b[MM];
pair<int,int> dp[1 << 20];
// .fi = so nguoi co the tra luong tinh den hien tai
// .se = so tien dang co
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];

    for(int mask = 0;mask < (1 << m);mask++) {
        for(int i = 0;i < m;i++) {
            if(mask >> i & 1) {
                int p_mask = mask ^ (1 << i);
                int nums = dp[p_mask].fi, cur_coin = dp[p_mask].se;
                if(cur_coin + b[i] == a[nums]) {
                    dp[mask] = max(dp[mask],{nums+1,0});
                }
                else if(cur_coin + b[i] < a[nums]) {
                    dp[mask] = max(dp[mask],{nums,cur_coin + b[i]});
                }
            }
        }
    }
    for(int mask = 0;mask < (1 << m);mask++) {
        if(dp[mask] == make_pair(n,0)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}