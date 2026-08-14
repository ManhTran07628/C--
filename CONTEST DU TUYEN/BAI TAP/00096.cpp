#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
ll n,m,q[MM],diff[MM];
struct QR{int l,r,x;} qr[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 1;i <= n;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].x;
    }

    for(int i = 1;i <= m;i++) {
        cin >> q[i];

        
        int res = 0;
        for(int j = 1;j <= n;j++) {

            if(qr[j].l <= q[i] && q[i] <= qr[j].r) {
                int fval = qr[j].l % 2;

                if( q[i] % 2 == fval ) res += qr[j].x;
                else res -= qr[j].x;

            }

        }
        cout << res << '\n';
    }


    
    return 0;   
}