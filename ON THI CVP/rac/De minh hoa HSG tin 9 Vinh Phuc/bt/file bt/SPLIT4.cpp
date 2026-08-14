#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main()
{
    for(int i = 1;i <= 4;i++) 
        cin >> a[i];
    sort(a+1,a+5);
    ll t1 = abs(a[1]+a[2]+a[3]-a[4]);
    ll t2 = abs(a[1]+a[2]-a[3]-a[4]);
    ll t3 = abs(a[1]+a[4]-a[2]-a[3]);
    ll t4 = abs(a[1]+a[3]-a[2]-a[4]);
    cout << min({t1,t2,t3,t4});
}