#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[501][501];

int score(int x1,int y1,int x2,int y2)
{
    return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int ans = 1000000;
    for(int i = 2;i < n;i++) {
        for(int j = 2;j < n;j++) {
            int d1 = score(1,1,i,j);
            int d2 = score(1,j+1,i,n);
            int d3 = score(i+1,1,n,j);
            int d4 = score(i+1,j+1,n,n);
            ans = min(ans,max({d1,d2,d3,d4})-min({d1,d2,d3,d4}));
        }
    }
    cout << ans;
    return 0;
}