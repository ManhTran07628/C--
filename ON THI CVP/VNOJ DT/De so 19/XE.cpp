#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "XE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll cnt = 0,sum = 0;
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum << '\n';
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] > 20) {
             cout << i << '\n';
             cnt = 1;
        }
    }
    if(cnt == 0) cout << 0;
    return 0;
}