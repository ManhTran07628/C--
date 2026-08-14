#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

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
    ll n,S;
    cin >> n >> S;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll pos = lower_bound(b+1,b+n+1,b[i]-S) - b - 1;
        cout << b[pos] << '\n';
    }
    cout << ans;
    return 0;
}