#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "timx"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll tbc = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll kq = 1e18,sox = 0;
    ll L = 1,R = 1e15;
    while(L <= R) {
        ll mid = (L+R) / 2;
        ll tong = 0;
        for(int i = 1;i <= n;i++) {
            tong += abs(a[i]-mid);
        }
        if(tong < kq) {
            kq = tong;
            sox = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << sox;
    return 0;
}
