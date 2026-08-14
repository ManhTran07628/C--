#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 100 + 7;
int n,m,a[MM][MM],b[MM][MM],c[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
            c[i][j] = a[i][j];
        }

    ll cnt1 = 0, cnt2 = 0;
   for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int parity1 = (i + j) % 2; 
            if (a[i][j] % 2 == parity1) b[i][j] = a[i][j];
            else b[i][j] = a[i][j] + 1;
            cnt1 += b[i][j];

            int parity2 = 1 - parity1;
            if (a[i][j] % 2 == parity2) c[i][j] = a[i][j];
            else c[i][j] = a[i][j] + 1;
            cnt2 += c[i][j];
        }
    }


    if(cnt1 > cnt2) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                cout << c[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else if(cnt1 < cnt2) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else if(cnt1 == cnt2) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(c[i][j] == b[i][j]) continue;
                else {
                    if(c[i][j] > b[i][j]) {
                        for(int i = 1;i <= n;i++) {
                            for(int j = 1;j <= m;j++) {
                                cout << b[i][j] << ' ';
                            }
                            cout << '\n';
                        }
                        return 0;
                    }
                    else {
                        for(int i = 1;i <= n;i++) {
                            for(int j = 1;j <= m;j++) {
                                cout << c[i][j] << ' ';
                            }
                            cout << '\n';
                        }
                        return 0;
                    }
                }
            }
        }
    }
    // cout << cnt1 << ' ' << cnt2;
    return 0;
}