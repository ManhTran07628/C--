#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "souoc"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            if(i % 2 != 0) ans++;

            if(n / i != i) {
                if((n/i) % 2 != 0) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}