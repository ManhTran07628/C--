#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tong"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll ans = 0;
    for(int i = 1;i <= 4;i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) ans += a[i];
    }
    cout << ans;
    return 0;
}