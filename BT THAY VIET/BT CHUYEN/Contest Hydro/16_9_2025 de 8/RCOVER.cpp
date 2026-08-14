#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int w,h,n,a[1500][1500];
int XX1 = MM,YY1 = MM,XX2 = 0,YY2 = 0;

void readinput()
{
    cin >> w >> h;
    cin >> n;
    for(int q = 1;q <= n;q++) {
        int X1,Y1,X2,Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        for(int i = X1;i <= X2;i++) {
            for(int j = Y1;j <= Y2;j++) {
                a[i][j] = q;
            }
        }
        XX1 = min(XX1,X1);
        YY1 = min(YY1,Y1);
        XX2 = max(XX2,X2);
        YY2 = max(YY2,Y2);
    }
}
int lt[MM];

void solve()
{
    int ans = 0;
    // cout << XX1 << ' ' << YY1 << ' ' << XX2 << ' ' << YY2 << '\n';
    for(int X1 = 1;X1+w-1 <= XX2;X1++) {
        for(int Y1 = 1;Y1+h-1 <= YY2;Y1++) {
            int X2 = X1+w-1, Y2 = Y1+h-1;
            
            int cnt = 0;

            for(int i = X1;i <= X2;i++) {
                for(int j = Y1;j <= Y2;j++) {
                    if(a[i][j] != 0 && lt[a[i][j]] == 0) {
                        lt[a[i][j]] = 1;
                        cnt++;
                    }
                }
            }

            ans = max(ans,cnt);
            for(int i = 1;i <= n;i++) lt[i] = 0;
        }
    }
    cout << ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}