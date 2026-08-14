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
    ll n;
    cin >> n;
    for(int i = 1;i<= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j<= n;j++) {
            ll ans = lower_bound(a+j,a+n+1,a[i]+a[j]) - a - 1;
            if(ans != n+1) {
                dem += ans - j;
            }
        }
    }
    cout << dem;
    return 0;
}