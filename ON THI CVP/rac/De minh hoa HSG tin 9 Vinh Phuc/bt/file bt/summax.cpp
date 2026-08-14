#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SUMMAX"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll tong1 = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = -a[i];
        tong1 += a[i];
    }
    ll tong = 0;
    ll min1 = 1e9,vt;
    for(int i = 1;i <= n;i++) {
        tong += a[i];
        if(min1 > tong) {
            vt = i;
            min1 = tong;
        }
        if(tong > 0) {
            tong = 0;
        }
    }
    cout << tong1 - min1 - min1;
    return 0;
}
