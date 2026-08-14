#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 500 + 7;
int n,m,K,a[MM][MM];

int getsum(int X1,int Y1,int X2,int Y2)
{
    return a[X2][Y2] - a[X1 - 1][Y2] - a[X2][Y1 - 1] + a[X1 - 1][Y1 - 1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> K;
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;
        for(int j = 1;j <= m;j++) {
            a[i][j] = s[j - 1] - '0';
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++) {
        for(int k = i;k <= n;k++) {
            for(int j1 = 1,j2 = 1;j2 <= m;j2++) {

                while(j1 <= m && getsum(i,j1,k,j2) > K) j1++;

                if(getsum(i,j1,k,j2) <= K) {
                    // cout << i << ' ' << j1 << ' ' << k << ' ' << j2 << '\n';
                    res = max(res,(j2 - j1 + 1) * (k - i + 1));
                }

            }
        }
    }

    cout << res;

    
    return 0;
}