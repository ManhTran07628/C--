#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "XOAPT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll tong = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tong += a[i];
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        dem += ((tong-a[i]) % 2 == 0 ? 1 : 0); 
    }
    cout << dem;
    return 0;
}