#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i];

    ll min1 = 1e18;
    ll L = 1,R = 1e18;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll tong = 0,dem = 1,kt = 1;
        for(int i = 1;i <= n;i++) {
            if(mid < a[i]) {
                kt = 0;
                break;
            }
            if(tong + a[i] <= mid) {
                tong += a[i];
            }
            else {
                dem++;
                tong = a[i];
            }
        }
        if(kt == 0) {
            L = mid + 1;
            continue;
        }
        if(dem >= k) {
            min1 = min(min1,mid);
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << min1;
    return 0;
}