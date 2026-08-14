#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
ll a[N][N],b[N][N];
int main()
{
    ll n,m,q;
    cin >> n >> m;
    ll max1 = -1e18;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            b[i][j] = b[i][j-1] + a[i][j];
        }
    }
    for(int i = 1;i <= m;i++) {
        for(int j = i;j <= m;j++) {
            ll s = 0;
            for(int k = 1;k <= n;k++) {
                s += (b[k][j] - b[k][i-1]);
                max1 = max(max1,s);
                if(s < 0) {
                    s = 0;
                }
            }
        }
    }
    cout << max1;
    return 0;
}
