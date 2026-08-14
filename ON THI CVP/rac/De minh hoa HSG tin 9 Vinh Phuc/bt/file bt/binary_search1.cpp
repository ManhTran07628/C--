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
    ll n,t;
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll L = 1,R = 1e18,kq = 0;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll tong = 0;
        for(int i = 1;i <= n;i++) {
            tong += mid / a[i];
        }
        if(tong >= t) {
            kq = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    cout << kq;
    return 0;
}