#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,q,tong = -1e9,tongdoan = 0,max1 = -1e9;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            tongdoan += a[i];
            max1 = max(max1,tongdoan);
            if(tongdoan < 0) tongdoan = 0;
        }
        tong = a[1];
        for(int i = 2;i <= n;i++) {
            if(tong + a[i] > tong)  tong += a[i];
            if(a[i] > tong) tong = a[i];
        }
        cout << tong << " " << max1 << '\n';
    }
    return 0;
}