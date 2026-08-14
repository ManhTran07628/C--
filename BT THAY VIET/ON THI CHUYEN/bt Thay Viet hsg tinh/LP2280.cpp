#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[5001][5001],b[5001][5001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    ll mcot = 0,mhang = 0;
    while(n--) {
        ll x,y,v;
        cin >> x >> y >> v;
        mhang = max(mhang,x);
        mcot = max(mcot,y);
        a[x][y] += v;
    }
    b[0][0] = a[0][0];
    for(int i = 1;i <= mhang;i++) b[i][0] = b[i-1][0] + a[i][0]; // hang
    for(int i = 1;i <= mcot;i++) b[0][i] = b[0][i-1] + a[0][i]; //cot
    for(int i = 1;i <= mhang;i++) {
        for(int j = 1;j <= mcot;j++) {
            b[i][j] = b[i][j-1] + a[i][j];
        }
    }
     for(int i = 1;i <= mhang;i++) {
        for(int j = 1;j <= mcot;j++) {
            b[i][j] = b[i-1][j] + b[i][j];
        }
    }
    ll max1 = 0;
    for(int i = 0;i <= mhang;i++) {
        for(int j = 0;j <= mcot;j++) {
            ll x1 = i-m;
            ll y1 = j-m;
            ll x2 = i;
            ll y2 = j;
            ll cnt = b[x2][y2];
            if(x1 > 0) {
                cnt -= b[x1][y2];
            }
            if(y1 > 0) {
                cnt -= b[x2][y1];
            }
            if(x1 > 0 && y1 > 0) {
                cnt += b[x1][y1];
            }
            max1 = max(max1,cnt);
        }
    }
    cout << max1;
    return 0;
}