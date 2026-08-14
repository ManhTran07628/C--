#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cost"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> f[i];
        if(f[i] == 2) {
            ans += a + b;
        }
        else ans += min(a,b);
    }
    cout << ans;
    return 0;
}