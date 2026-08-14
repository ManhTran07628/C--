#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[10][10];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,w,k;
    cin >> h >> w >> k;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '#' ? 1 : 0);
        }
    }
    int ans = 0;
    for(int mask_h = 0;mask_h < (1 << h);mask_h++) {
        for(int mask_w = 0;mask_w < (1 << w);mask_w++) {
            int cnt = 0;
            int width[10] = {},height[10] = {};
            for(int i = 0;i < h;i++) 
                if((mask_h >> i) & 1) height[i+1] = 1;

            for(int i = 0;i < w;i++) 
                if((mask_w >> i) & 1) width[i+1] = 1;

            for(int i = 1;i <= h;i++) {
                for(int j = 1;j <= w;j++) {
                    if(height[i] || width[j]) continue;
                    cnt += (a[i][j] == 1);
                }
            }
            ans += (cnt == k);
        }
    }
    cout << ans;
    return 0;
}