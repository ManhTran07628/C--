#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
ll a[N][N],b[N][N];
int main()
{
    ll n,m,q;
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    b[0][0] = a[1][1];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            b[i][j] = b[i][j-1] + a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            b[i][j] = b[i-1][j] + b[i][j];
        }
    }
    while(q--) {
        ll a1,b1,c1,d1;
        cin >> a1 >> b1 >> c1 >> d1;
        ll kq = b[c1][d1];
        if(a1 > 1) {
            kq = kq - b[a1-1][d1];
        }
        if(b1 > 1) {
            kq = kq - b[c1][b1-1];
        }
        if(a1 > 1 && b1 > 1) {
            kq = kq + b[a1-1][b1-1];
        }
        cout << kq << endl;
    }
    return 0;
}
