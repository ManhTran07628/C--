#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tongchuso"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ",out","w",stdout);
    }
    ll n;
    cin >> n;
    ll ans = 0;
    while(n > 0) {
        ans += n%10;
        n /= 10;
    }
    cout << ans;
    return 0;
}