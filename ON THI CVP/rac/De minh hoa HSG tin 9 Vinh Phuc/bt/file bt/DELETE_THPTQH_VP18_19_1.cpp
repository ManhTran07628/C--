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
    ll dem = 0;
    for (ll k = 2; k * (k - 1) / 2 < n; k++) {
        if ((n - k * (k - 1) / 2) % k == 0) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}