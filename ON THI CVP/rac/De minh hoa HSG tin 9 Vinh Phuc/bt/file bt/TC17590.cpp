#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N];
ll n;

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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll w;
    cin >> w;
    ll ans = 0;
    if(w == 0) {
        cout << "possible";
        return 0;
    }
    for(int i = n;i >= 1;i--) {
        ans += a[i];
        if(ans == w) {
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";
    return 0;
}