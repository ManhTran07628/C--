#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[1001][1001],b[1001][1001];
int w,h,n;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> w >> h >> n;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }
    int ans = 0;
    for(int x1 = 1;x1 <= h;x1++) {
        for(int y1 = 1;y1 <= w;y1++) {
            for(int k = 1;k * k <= n;k++) {
                int j = n/k;
                int x2 = min(x1+k-1,h),y2 = min(y1+j-1,w);
                int p = b[x2][y2] - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1];
                ans = max(ans,p);
                x2 = min(x1+j-1,h),y2 = min(y1+k-1,w);
                p = b[x2][y2] - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1];
                ans = max(ans,p);
            }
        }
    }
    cout << ans;
    // b[x2][y2] - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1];
    return 0;
}