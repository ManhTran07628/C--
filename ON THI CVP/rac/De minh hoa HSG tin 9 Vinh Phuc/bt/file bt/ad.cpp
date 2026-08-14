#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],trai[N],phai[N];

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
    ll n,kq = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        kq += a[i];
        trai[i] = max(trai[i-1],kq);
        if(kq < 0) kq = 0;
    }
    kq = 0;
    for(int i = n;i >= 1;i--) {
        kq += a[i];
        phai[i] = max(phai[i+1],kq);
        if(kq < 0) kq = 0;
    }
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        max1 = max(max1,trai[i-1]+phai[i]);
    }
    cout << max1;
    return 0;
}
