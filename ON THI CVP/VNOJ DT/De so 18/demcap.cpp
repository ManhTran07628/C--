#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "demcap"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll cnt = 0;
    for(int i = 2;i <= sqrt(n);i++) {
        ll n1 = n / i;
        if(n1 * i == n) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}