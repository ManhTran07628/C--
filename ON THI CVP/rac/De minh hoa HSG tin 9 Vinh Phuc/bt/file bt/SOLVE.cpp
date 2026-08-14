#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll tongcs(ll k)
{
    ll kq = 0;
    while(k > 0) {
        kq += k % 10;
        k /= 10;
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "solve"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll L = 1,R = 1e9,vt = -1;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll tmp = mid,kq = 0;
        bool kt = -1;
        for(ll i = max(1ll,mid-100);i <= mid+100;i++) {
            ll k = i*i+tongcs(i)*i;
            if(k == n) {
                kt = 1;
                vt = i;
                R = mid - 1;
                break;
            }
        }
        if(kt == -1) {
            if(mid*mid+tongcs(mid)*mid == n) {
                vt = mid;
                R = mid - 1;
            }
        }
        else if (mid*mid+tongcs(mid)*mid > n)
            R = mid - 1;
        else if(mid*mid+tongcs(mid)*mid < n)
            L = mid + 1;
    }
    cout << vt;
    return 0;
}
