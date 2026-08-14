#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],trai[N],phai[N],b[N];

ll tmp = 2e9;
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
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++) {
        trai[i] = max(trai[i-1],a[i]);
    }
    phai[n] = a[n];
    for(int i = n;i >= 1;i--) {
        phai[i] = max(phai[i+1],a[i]);
    }
    for(int i = 1;i <= n;i++) {
        b[i] = min(trai[i],phai[i]) - a[i];
    }
    ll L = 1,R = tmp,min1 = -1;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll tong = 0;
        for(int i = 1;i <= n;i++) {
            if(mid <= a[i])
                tong += b[i];
            else {
                if(b[i] - mid + a[i] >= 0) {
                    tong += b[i] - mid + a[i];
                }
            }
        }
        if(tong >= m) {
            min1 = tong;
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
    }
    cout << min1;
    return 0;
}


