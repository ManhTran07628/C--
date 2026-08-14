#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int p[15],c[15];
int dp[1025][1005]; // dp[mask][i] so diem lon nhat co the kiem duoc
// khi xet den trang thai mask va thuc hien i bai 

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int D,G;
    cin >> D >> G;
    int st = 0;
    for(int i = 1;i <= D;i++) {
        cin >> p[i] >> c[i];
        st += p[i];
    }
    int ans = st;
    for(int mask = 1;mask < (1 << D);mask++) {
        for(int k = 1;k <= st;k++) {
            for(int i = 0;i < D;i++) {
                if((mask >> i) & 1) {
                    for(int j = 0;j <= p[i+1];j++) {
                        int prev_mask = mask ^ (1 << i);
                        int score = j*(i+1)*100;
                        if(j == p[i+1]) score += c[i+1];
                        if(k >= j) 
                            dp[mask][k] = max(dp[mask][k],dp[prev_mask][k-j]+score);
                        if(dp[mask][k] >= G) {
                            ans = min(ans,k);
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}

