#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[201][201];
int n,k;
bool countballons(int x,int y)
{
    int cnt = a[x][y];
    for(int i = 1;i <= n;i++)  {
        if(i == y) continue;
        cnt += a[x][i];
    }
    for(int i = 1;i <= n;i++) {
        if(i == x) continue;
        cnt += a[i][y];
    }
    int d1 = x-min(x,y);
    int d2 = y-min(x,y);
    for(int i = 1;i <= n;i++) {
        if(d1+i == x && d2+i == y) continue;
        cnt += a[d1+i][d2+i];
    }
    for(int i = 1;i <= n;i++) {
        cnt += a[x+i][y-i];
    }
    for(int i = 1;i <= n;i++) {
        cnt += a[x-i][y+i];
    }
    return cnt == k;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= k;i++) {
        int r,c;
        cin >> r >> c;
        a[r][c]++;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            ans += countballons(i,j);
        }
    }
    cout << ans;
    return 0;
}