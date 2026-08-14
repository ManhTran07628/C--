#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],max1 = -1e9;
ll n,m,j;
ll tmp = 1e9 + 7;
int main()
{
    //freopen("RIVER.INP","r",stdin);
   // freopen("RIVER.OUT","w",stdout);
    cin >> n >> m >> j;
    for(int i = 1;i <= n;i++) {
        ll j = i - 1;
        a[i] = 1 + (j*j % m);
        b[i] = b[i-1] + a[i];
    }
    ll L = 1,R = b[n],kq = -1;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll ans = 0,k = 0,kt = 1;
        for(int i = 1;i <= n;i++) {
            if(b[i] - b[k] > mid) {
                ans++;
                k = i-1;
                if(b[i] - b[k] > mid) {
                    kt = 0;
                    break;
                }
            }
        } 
        ans++;
        if(kt == 1 && ans <= j) {
            kq = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << kq;
    return 0;
}
